#include <iostream>       // std::cout
#include <thread>         // std::thread
using namespace std;

int countValue = 0; //global variable
void task1();
void task2();

int main()
{
	//creating threads
	thread th1(task1);
	thread th2(task2);
	th1.join();
	th2.join();

	return 0;
}
void task1() {
	while (countValue < 50) {
		countValue = countValue + 1;
		cout << "\nA: countValue =" << countValue << endl;
	}
	cout << "\n A wins" << endl;
	exit(0);
}
void task2() {
	while (countValue > -50) {
		countValue = countValue - 1;
		cout << "\nB: countValue =" << countValue << endl;
	}
	cout << "\n B wins" << endl;
	exit(0);
}
