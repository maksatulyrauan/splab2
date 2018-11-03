#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	pid_t x = fork();
	if(x == 0) { //child
		 
		pid_t y = fork();
		if(y == 0) {
			pid_t r = fork();
			if(r == 0) {
				char *myargs[5];
				myargs[0] = strdup("python");
				myargs[1] = strdup("add.py");
				myargs[2] = argv[1];
				myargs[3] = argv[2];
				myargs[4] = NULL;
				execvp(myargs[0], myargs);
			}
			else {
				waitpid(r, 0, 0);
				char *myargs1[5];
				myargs1[0] = strdup("java");
				myargs1[1] = strdup("sub");
				myargs1[2] = argv[1];
				myargs1[3] = argv[2];
				myargs1[4] = NULL;
				execvp(myargs1[0], myargs1);
			}
		}
		else {
			waitpid(y, 0, 0);
			char *myargs2[5];
			myargs2[0] = strdup("js");
			myargs2[1] = strdup("multi.js");
			myargs2[2] = argv[1];
			myargs2[3] = argv[2];
			myargs2[4] = NULL;
			execvp(myargs2[0], myargs2);
		} 

	}

	else {
		waitpid(x, 0, 0);
		pid_t p = fork();
		if(p == 0) {
			char *myargs3[4];
			myargs3[0] = strdup("./div.sh");
			myargs3[1] = argv[1];
			myargs3[2] = argv[2];
			myargs3[3] = NULL;
			execvp(myargs3[0], myargs3);
		}
		else {
			waitpid(p, 0, 0);
			printf("parent: done \n");

		} 
		 

	}
}
