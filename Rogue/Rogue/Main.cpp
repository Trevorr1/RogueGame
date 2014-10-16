#include <stdio.h>
#include "Manager.h"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, const char* argv[])
{
	printf("\nHello World\n\n");

	Manager*  manager = new Manager();
	
	while (true){
		chrono::milliseconds dura(2000);
		this_thread::sleep_for(dura);
		printf("Thread sleep 2 sec \n\n");
	}
}