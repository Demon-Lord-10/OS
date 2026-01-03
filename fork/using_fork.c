#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>	//wait is not supported in C99


int main()
{
	printf("Entered Parent Process \n");

	pid_t pid;

	pid=fork();
	
	if(pid<0){
		fprintf(stderr,"FORK FAILED");
		return 1;
	}
	else if(pid==0){
		//Child Process
		
		printf("Entered Child Process \n");

		execlp("/bin/ls","ls",NULL);
		
		printf("After Exec() in child \n");
	}
	else{
		//parent process
		printf("Entered Parent Process(again) \n");
		wait(NULL);
		printf("Child Complete \n");
	}
	return 0;


}
