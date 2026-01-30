#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(){
	int fd;
	char filename[255];
	char buf[255];
	int bytes_read;

	printf("Enter the name of the file to be read: \t");
	scanf("%255s",filename);
	
	if((fd=open(filename,O_RDONLY))==-1){
		perror("Failed");
		exit(1);
	}

	while((bytes_read = read(fd,buf,sizeof(buf)))>0)
	{
		write(STDOUT_FILENO,buf,bytes_read);
	}

	close(fd);

	return 0;
}
