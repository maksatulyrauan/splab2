#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	pid_t x = fork();
	if(x == 0) { //child
		printf("child1: %d+%d=%d \n", a, b, a + b);
		pid_t y = fork();
		if(y == 0) {
			printf("child2: %d-%d=%d \n", a, b, a - b);
		}
		else {
			waitpid(y, 0, 0);
			printf("child3: %d*%d=%d \n", a, b, a * b);
		}

	}

	else {
		waitpid(x, 0, 0);
		pid_t p = fork();
		if(p == 0) {
			printf("child4: %d/%d=%d \n", a, b, a / b);
		}
		else {
			waitpid(p, 0, 0);
			printf("parent: done \n");

		} 
		 

	}
}
