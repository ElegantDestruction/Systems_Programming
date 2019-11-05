#include <iostream>
#include <thread>
#include <vector>
using namespace std;
int counter = 0;

void race() {
	int count = 0;
	std::thread::id tid = this_thread::get_id();
	this_thread::yield();

	for (int i = 0; i < 1000000; i++) {
		counter = counter + 1;
		count++;
	}
	cout << "\nThread  " << tid << "  calculated " << count << endl;
}


int main(void) {
	vector <thread> raceThreads;

	for (int i = 0; i < 2; i++)
		raceThreads.push_back(thread(race));
	for (thread& t : raceThreads)
		t.join();
	cout << "The final counter is " << counter << endl;
}
