#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/fdtable.h>
#include <linux/fs.h>
#include <linux/pid.h>
#include <linux/fs_struct.h>

SYSCALL_DEFINE1(open_file_sizes, int, pid)
{
    struct task_struct *task;
    struct files_struct *files;
    struct fdtable *fdt;
    long total_size = 0;
    int i;

    rcu_read_lock();
    task = pid_task(find_vpid(pid), PIDTYPE_PID);
    if (task != NULL) {
        files = task->files;
        fdt = files_fdtable(files);

        for (i = 0; i < fdt->max_fds; i++) {
            struct file *file = fdt->fd[i];
            if (file != NULL) {
                struct kstat stat;
                if (vfs_getattr(&file->f_path, &stat, STATX_SIZE, AT_STATX_SYNC_AS_STAT) == 0) {
                    total_size += stat.size;
                }
            }
        }
    }
    rcu_read_unlock();

    return total_size;
}
