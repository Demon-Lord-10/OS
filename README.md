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

