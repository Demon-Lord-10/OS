#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 25  //--> buffer size
#define READ_END 0	// --> in file descriptor 0 is console
#define WRITE_END 1	// --> in file descriptor 1 is stdder


int main()
{
	char write_msg[BUFF_SIZE] = "Bruh";
	char read_msg[BUFF_SIZE];

	int fd[2];	//fd -> file descriptor
	pid_t pid;

	//Creating Pipe
	if(pipe(fd) == -1){
		fprintf(stderr,"Pipe Failed");
		return 1;
	}

	pid = fork();


	if(pid < 0){
		fprintf(stderr,"Fork Failed");
		return 1;
	}

	if(pid > 0){
		//close the unused end of the pipe
		close(fd[READ_END]);

		//write to the pipe
		write(fd[WRITE_END],write_msg,BUFF_SIZE);

		//close the read end of the pipe
		close(fd[WRITE_END]);
	}
	else{
		//child process

		//close the unused end of the pipe
		close(fd[WRITE_END]);
		
		//read from the pipe
		read(fd[READ_END],read_msg,BUFF_SIZE);
		printf("read %s",read_msg);
		//close the write end of the pipe
		close(fd[READ_END]);
	}
}

