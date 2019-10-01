#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int main() {
	
	int test_int = 25;
	pid_t pid;

	pid = fork();

	if (pid == 0) {
		cout << "Child process has been created " << test_int << endl;
	}
	else if (pid < 0) {
		cout << "No new child was created" << endl;
	}
	else {
		wait(0);
		cout << "I AM AN ADULT!!!!!!!!!!! (the parent)" << endl;
	}

	return 0;
}
