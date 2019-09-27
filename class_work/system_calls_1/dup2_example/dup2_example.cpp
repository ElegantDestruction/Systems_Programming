#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	//system call open() returns a file descriptor fd to the file "duptest.txt"
	int oldFD = dup(STDOUT_FILENO);
	int fd = open("dup2test.txt", O_WRONLY | O_APPEND);

	if (fd < 0) { //failed to open
		cout << "Cannot open the file" << endl;
		exit(1);
	}

	//here the newfd is the file descriptor of stdout (ie 1)
	dup2(fd, 1);

	//All the output statements will be written in the file
	cout << "I will be written to the file dup2test.txt" << endl;

	//write() will write msg1 and msg2 to the file using the fd
	string msg1 = "I am Jacob Hillebrand\n";
	string msg2 = "I live in Menomonie\n";
	cout << msg1;
	
	write(fd, (char *)msg2.c_str(), msg2.size());

	fflush(stdout);
	close(fd);

	dup2(oldFD, 1);
	cout << "Does this print to console?" << endl;
	return 0;


}
