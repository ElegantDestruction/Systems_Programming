#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>

using namespace std;
const int SIZE = 3;
int sharedTotal = 0;
mutex mutexLocker1, mutexLocker2;

void shared_increament_thread_even(int i, int threadID)
{
	lock_guard<mutex> guard1(mutexLocker1);
	cout << "\nAquired the first locker by " << threadID << endl;
	lock_guard<mutex> guard2(mutexLocker2);
	cout << "\nAquired the second locker by " << threadID << endl;
	cout << "\nSharedTotal Current Value is " << sharedTotal << endl;
	sharedTotal++;

	cout <<"\nThread "<< threadID<< " is releasing lockers..." << endl;
}

void shared_increament_thread_odd(int i, int threadID)
{
	//std::this_thread::sleep_for(std::chrono::microseconds(6000));
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	lock_guard<mutex> guard2(mutexLocker2);
	cout << "\nAquired the second locker by " << threadID << endl;
	lock_guard<mutex> guard1(mutexLocker1);
	cout << "\nAquired the first locker by " << threadID << endl;	
	cout << "\nSharedTotal Current Value is " << sharedTotal << endl;
	sharedTotal++;
	cout << "\nThread " << threadID << " is releasing lockers..." << endl;
}



void run(int threadID)
{
	if (threadID % 2 == 0) //threads with even IDs
		for (int i = 0; i < SIZE; i++) {
			shared_increament_thread_even(i, threadID);
		}

	else  //threads with odd IDs
		for (int i = 0; i < SIZE; i++) {
			shared_increament_thread_odd(i, threadID);
		}

}

int main()
{
	thread t1(run, 1);
	thread t2(run, 2);
	thread t3(run, 3);
	thread t4(run, 4);
	thread t5(run, 5);
	thread t6(run, 6);


	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	cout << "Total= " << sharedTotal << endl;
	return 0;
}
