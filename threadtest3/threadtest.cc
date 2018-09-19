#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

struct 

 void hello();

int main(void)
{
	vector<thread> vec_threads;
	for(int i=0; i < 5; i++)
	{
		vec_threads.push_back(thread(hello));
	}

	for(auto& thread : vec_threads)
	{
		thread.join();
	}
	
	//t1.join();
	cout << "threads end " << endl;

	exit(0);

}

void hello()
{
	//printf("hello from thread: %d\n ",(int)this_thread::get_id());
	cout << "thread id is " << this_thread::get_id() << endl;
}
