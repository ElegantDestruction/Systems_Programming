#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>
#include<string>

using namespace std;

int main() {
	
	//system call open() returns a file descriptor fd to the file
	//"duptest.txt" stores in the same location
	

	int fd = open("duptest.txt", O_WRONLY | O_APPEND);

	if (fd < 0) {
		cout << "Can not open the file" << endl;
		exit(1);

	} //end if

	//dup() will create the copy of fd as the copy_fd then both can be 
	//used interchangeably
	int copy_fd = dup(fd);

	//write() will write msg1 and msg2 to the file using the file descriptors
	string msg1 = "I am Jacob Hillebrand\n";
	string msg2 = "I live in Menomonie\n";

	//writing via the copy file descriptors
	write(copy_fd, (char *)msg1.c_str(), msg1.size());

	//writin via the original file decriptors
	write(fd, (char *)msg2.c_str(), msg2.size());

	return 0;

}
