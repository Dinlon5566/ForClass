#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/fdtable.h>
#include <linux/fs.h>
#include <linux/pid.h>

SYSCALL_DEFINE1(number_of_files_opened,int,pid)
{
    struct task_struct *task;
    struct files_struct *files;
    struct fdtable *fdt;
    int file_count = 0;
    int i;

    rcu_read_lock();
    task = pid_task(find_vpid(pid), PIDTYPE_PID);
    if (task != NULL) {
        files = task->files;
        fdt = files_fdtable(files);

        /* Traverse the fd table */
        for (i = 0; i < fdt->max_fds; i++) {
            if (fdt->fd[i] != NULL) {
                file_count++;
            }
        }
    }
    rcu_read_unlock();

    return file_count;
}

