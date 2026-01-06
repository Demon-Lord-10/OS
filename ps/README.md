# ps

Implemented ps - report a snapshot of the current processes.

## How to build

Use the following command.

```bash
make
```
## Output

Use the following command to run.

```bash
make run
```
Output:  
```
PID CMD
1   systemd
...........
```
How does it work?

First we obtain the fd(file descriptor) of the directory /proc and then wrap it to DIR* using fdopendir and get the fd to /proc.  
Next we go to the next entry in the dir using readdir().  
We check if the current dir name is pid by checking if its a digit.  
Obtain the information about the file by using the fstatat (to obtain fd(dfd) to the dir/file /proc/pid(some pid)) then check if it is a directory.  
Obtain the file path (relative path to /proc/pid/comm) and use the openat to obtain the fd(ffd) for the given file.  
Read the fd(ffd) and get the cmd , then print in the required format.  

## References 
https://www.man7.org/linux/man-pages/man1/ps.1.html
https://www.man7.org/linux/man-pages/man5/proc.5.html
https://www.man7.org/linux/man-pages/man0/dirent.h.0p.html
https://www.man7.org/linux/man-pages/man3/fdopendir.3p.html
https://www.man7.org/linux/man-pages/man3/readdir.3.html
https://www.man7.org/linux/man-pages/man5/proc_pid_comm.5.html
https://www.man7.org/linux/man-pages/man3/fstatat.3p.html
https://www.man7.org/linux/man-pages/man2/open.2.html
https://www.man7.org/linux/man-pages/man2/openat2.2.html
https://www.man7.org/linux/man-pages/man2/stat.2.html
https://www.man7.org/linux/man-pages/man2/wait.2.html  
