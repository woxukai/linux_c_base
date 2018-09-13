#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>

using namespace std;

 void sig_int();

int main(void)
{
	std::thread t1(sig_int);
	t1.join();
	cout << "t1 end " << endl;

	exit(0);

}

void sig_int()
{
	printf("\n in sig_int: ");
}
