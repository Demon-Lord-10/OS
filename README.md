# Unix System Utilities in C

Implementation of core Unix command-line utilities using low-level POSIX system calls in C.

## Description

This project reimplements fundamental Unix commands from scratch using system calls (`open()`, `read()`, `write()`, `fork()`, `exec()`, `opendir()`, etc.) to understand operating system internals and systems programming concepts.

## Implemented Commands

- **ls** - List directory contents using `opendir()`, `readdir()`, and `stat()`
- **ps** - Display running processes by parsing `/proc` filesystem
- **cat** - Concatenate and display file contents with `read()` and `write()`
- **grep** - Search for patterns in files using character-by-character reading
- **fork** - Process creation demonstration using `fork()` system call
- **pipe** - Inter-process communication using `pipe()` and file descriptors

## References

### System Call Documentation
- [open(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/open.2.html)    
- [close(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/close.2.html)    
- [read(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/read.2.html)    
- [write(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/write.2.html)  
- [fork(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/fork.2.html)  
- [wait(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/wait.2.html)  
- [pipe(2) - Linux Manual Page](https://www.man7.org/linux/man-pages/man2/pipe.2.html)  

### Directory and File Operations
- [readdir(3) - Linux Manual Page](https://www.man7.org/linux/man-pages/man3/readdir.3.html)  
- [fdopendir(3) - Linux Manual Page](https://www.man7.org/linux/man-pages/man3/fdopendir.3p.html)  
- [dirent.h - Linux Manual Page](https://www.man7.org/linux/man-pages/man0/dirent.h.0p.html)  

### Command Reference
- [cat(1) - Linux Manual Page](https://www.man7.org/linux/man-pages/man1/cat.1.html)  
- [grep(1) - Linux Manual Page](https://www.man7.org/linux/man-pages/man1/grep.1.html)  
- [ls(1) - Linux Manual Page](https://www.man7.org/linux/man-pages/man1/ls.1.html)  

### Process and System Information
- [proc(5) - Linux Manual Page](https://www.man7.org/linux/man-pages/man5/proc.5.html)  
- [execlp(3) - Linux Man Page](https://linux.die.net/man/3/execlp)  

### C Standard Library
- [strstr() - C String Function Reference](https://en.cppreference.com/w/c/string/byte/strstr)  

