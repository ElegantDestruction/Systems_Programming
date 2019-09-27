#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

#define MAX_NUM 1000



int main(){
	int random;
	srand(time(NULL));
	cout << "Ten random numbers (1-1000):\n";

	for (int i = 0; i < 10; i++) {
		random = rand()%MAX_NUM;
		cout << random << endl;
	}

	return 0;

}
