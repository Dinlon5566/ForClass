# linux_lab2

---
Code by Dinlon5566 @ 2023/06/09
Linux 6.0.1 x86_64
---
## number of files opened  
  
Write a system call, number_of_files_opened(int pid),  which a C program can invoke to report the number of files currently opened by a particular process identified by the user from the command line.

ex.

shell> Please enter the process id

shell> 128 (input by the user)

shell>  There are xxxx files currently opened by the process id 128.

---
## open file sizes  

Write a C program, namely open_file_sizes.c, which uses a system call, open_file_sizes( ) to report the total number of bytes for files currently opened by a particular process identified by its process id. 

ex.

shell> Please enter the process id

shell> 128 (input by the user)

shell> The total number of bytes for files opened by the process 128 is XXXX bytes.