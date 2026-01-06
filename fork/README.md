# Fork

fork() creates a new process by duplicating the calling process.
       The new process is referred to as the child process.  The calling
       process is referred to as the parent process.

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
Entered Parent Process  
Entered Parent Process(again)   
Entered Child Process   
README.md  makefile  using_fork	 using_fork.c  
Child Complete
```

Note: After Exec() doesnt print as execlp() replaces the current process with ls.

## References 

https://www.man7.org/linux/man-pages/man2/fork.2.html  
https://linux.die.net/man/3/execlp  
https://www.man7.org/linux/man-pages/man2/wait.2.html  
