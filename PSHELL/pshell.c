#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char* argv[]) {
	char a[20];
	int y = 0;
	char o[20] = "exit";
	int e = 0;
	int pid[100] = { 0 };
	while(y != 1) {
		 

		printf("Enter your command: ");
		fgets(a, 100, stdin);
		char c = a[strlen(a) - 2];
		if(c == '&') {
			 
			strtok(a, " &");
			pid_t p = fork();
			
			if(p == 0) {
				char *myargs[2];
				myargs[0] = strdup(a);
				myargs[1] = NULL;
				execvp(myargs[0], myargs);
				 
				//exit(-1);
			}
			else {
				pid[e] = getpid();
				e += 1;
				continue;
				 
			}
			 
		}
		else {
			strtok(a, "\n");
			if(strcmp(a, o) == 0) {
				break;
			}
			else if(strcmp(a, "showjobs") == 0) {
				int i = 1;
				while(pid[i - 1] != 0) {
					printf("%d: [%d]\n", i, pid[i - 1]);
					i += 1;
				}
			}
			else {
				system(a);
			}
			 
		}
	}

}
