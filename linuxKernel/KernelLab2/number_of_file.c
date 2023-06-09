#include <stdio.h>

#include <unistd.h>

#include <sys/syscall.h>



#define sys_number_of_files_opened 548



int main(int argc,char* argv[]) {

   int pid;

   printf("Input the pid:\n");

   scanf("%d",&pid); 

    int file_count = syscall(sys_number_of_files_opened, pid);



    if (file_count < 0) {

        perror("syscall failed");

        return -1;

    }



    printf("Process with PID %d has %d open file(s)\n", pid, file_count);

    return 0;

}

