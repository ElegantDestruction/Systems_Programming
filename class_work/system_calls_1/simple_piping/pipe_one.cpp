#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {

	size_t Maxsize = 150;
	int fd[2], nbytes;
	pid_t childpid; 
	char readbuffer[150];
	char sharedStr_1[] = "Jacob Hillebrand\n";
	char sharedStr_2[] = "Computer and Electrical Engineering Dept.\n";
	char sharedStr_3[] = "hillebrandj3779@my.uwstout.edu\n";

	if(pipe(fd)<0) { //create a pipe
		exit(1); //error, no pipe was created
	}

	if((childpid = fork()) == -1) {
		perror("fork did not work; Sorry!");
		exit(1);
	}

	if(childpid == 0) {
		//Child Process closes up input side of pipe
		close(fd[0]);
		//Send "string" through the output side of pip
		write(fd[1], sharedStr_1, (strnlen(sharedStr_1, Maxsize/3)));
		write(fd[1], sharedStr_2, (strnlen(sharedStr_2, Maxsize/3)));
		write(fd[1], sharedStr_3, (strnlen(sharedStr_3, Maxsize/3)));
		exit(0);
	}

	else {
		wait(NULL);

		//Parent process closes up output side of pipe
		close(fd[1]);

		//Read in a string from the pipe
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		cout << "From Parent: Recieved String: " << endl << readbuffer << endl;
	}

	return(0);
}
