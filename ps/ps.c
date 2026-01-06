#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

int main() {
    struct stat statbuf;	//stores file attributes
    DIR *d;			//d points to DIR, A type representing a directory stream
    struct dirent *dp;		// Used to represent directory entries
				//struct dirent {
               			//ino_t          d_ino;       /* Inode number */
               			//off_t          d_off;       /* Not an offset; see below */
               			//unsigned short d_reclen;    /* Length of this record */
               			//unsigned char  d_type;      /* Type of file; not supported
               			//                               by all filesystem types */
               			//char           d_name[256]; /* Null-terminated filename */
           			//};
    int dfd, ffd;		// used to get the fd , where dfd is for directory and ffd is for file.

    if ((dfd = open("/proc", O_RDONLY | O_DIRECTORY)) == -1) {		//open dir and use it in readonly mode.(also /proc needs to be a dir)
        perror("open /proc");
        exit(1);
    }

    if ((d = fdopendir(dfd)) == NULL) {					//takes the raw fd and wraps it to *DIR format
        perror("fdopendir");
        exit(1);
    }

    printf("%-8s %s\n", "PID", "CMD");

    while ((dp = readdir(d)) != NULL) {					//readdir returns a pointer to the next entry in the dirent struct and returns NULL on reaching the end.
        if (!isdigit(dp->d_name[0])) continue;				//accept only if directory is number (pid)

        if (fstatat(dfd, dp->d_name, &statbuf, 0) == 0 && S_ISDIR(statbuf.st_mode)) { //check if dir and also obtain information about the file.
            
            char path[256];
            char cmd[256];
            
            snprintf(path, sizeof(path), "%s/comm", dp->d_name);	//get relative path

            if ((ffd = openat(dfd, path, O_RDONLY)) != -1) {		//open path relatively , /proc/pid/comm 
                
                ssize_t len = read(ffd, cmd, sizeof(cmd) - 1);		//get size of cmd , also read it to buffer cmd
                if (len > 0) {
                    cmd[len - 1] = '\0'; 				//lets say the size of cmd>256 but we will terminate it with our buffer size
                    printf("%-8s %s\n", dp->d_name, cmd);		// print the pid and cmd
                }
                close(ffd); 
            }
        }
    }

    closedir(d);
    return 0;
}

