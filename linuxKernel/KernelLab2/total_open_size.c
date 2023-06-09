#include <stdio.h>

#include <unistd.h>

#include <sys/syscall.h>



#define sys_open_file_sizes 549



int main() {

	int pid;

	printf("Input pid:\n");

	scanf("%d",&pid);

    long total_size = syscall(sys_open_file_sizes, pid);



    if (total_size < 0) {

        perror("syscall failed");

        return -1;

    }



    printf("Total size of files opened by process with PID %d is %ld bytes\n", pid, total_size);

    return 0;

}

