#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


int main(void){
	int fd;
	char pattern[256];
	char filename[256];
	char temp;
	char line[1024];
	int j = 0;

	printf("Enter pattern to search: ");
	scanf("%255s", pattern);

	printf("Enter filename: ");
	scanf("%255s", filename);

	if ((fd = open(filename, O_RDONLY)) == -1) {
	printf("No file found \n");
        perror("Failed");
        exit(1);
    	}

	while (read(fd, &temp, 1) > 0) {
        if (temp != '\n') {
            line[j++] = temp;
        } else {
            line[j] = '\0';
            if (strstr(line, pattern) != NULL) {
                printf("%s\n", line);
            }
            j = 0;
        }
    }
	close(fd);

	return 0;

}
