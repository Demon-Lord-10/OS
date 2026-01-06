#include<sys/stat.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
	struct dirent *dp;
	DIR *d;
	char s[256];


	printf("Enter(please enter <256)");
	scanf("%255s",s);

	if((d=fdopendir(open(s,O_RDONLY|O_DIRECTORY))) == NULL){
    	perror("Failed");
    	exit(1);
    	}

	while((dp=readdir(d)) != NULL){
		printf("%s\t",dp->d_name);
	}

	closedir(d);


	return 0;
}
