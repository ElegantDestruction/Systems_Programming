// DeadLockExamplesCPP_CS442FA19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Alnaeli
//references:
//cppreference.com
//http://www.cplusplus.com
/*
Quesion: What happens if a function quits or an exception is thrown before a mutex is unlocked?????
That is why you need to learn about Lock Guard Objects.  The idea is that the mutex is unlocked automatically 
released if the Lock Guard goes out of its scope :)

Lock guard
A lock guard is an object that manages a mutex object by keeping it always locked.
On construction, the mutex object is locked by the calling thread, and on destruction, the mutex is unlocked. 
It is the simplest lock, and is specially useful as an object with automatic duration that lasts until the end of its context.
In this way, it guarantees the mutex object is properly unlocked in case an exception is thrown.

So, the class lock_guard is a mutex wrapper that provides a convenient RAII-style mechanism for owning a mutex for the duration of a scoped block.
When a lock_guard object is created, it attempts to take ownership of the mutex it is given. 
When control leaves the scope in which the lock_guard object was created, the lock_guard is destructed and the mutex is released.
The lock_guard class is non-copyable.
*/
//EXAMPLE:

#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
mutex sharedVariable_mutex;  // to protect sharedVariable
int sharedVariable = 0;
void safetyGuaranteed_increment();

int main()
{
	 cout << "main: " << sharedVariable << '\n';
	 thread th1(safetyGuaranteed_increment);
	 thread th2(safetyGuaranteed_increment);
	th1.join();
	th2.join();
	 cout << "From main: " << sharedVariable << '\n';
}
void safetyGuaranteed_increment()
{
	 lock_guard< mutex> lock(sharedVariable_mutex);
	++sharedVariable;
	 cout <<  this_thread::get_id() << ": " << sharedVariable << '\n';
	// sharedVariable_mutex is automatically released when lock
	// goes out of scope
}
