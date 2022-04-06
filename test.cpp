#include <iostream>
#include <unistd.h>
#include <sys/types.h>
using namespace std;

extern int global_var;

void test1() {
	pid_t pid1, pid2, pid3;
	pid1 = getpid();
	global_var = 0;
	pid2 = fork();

	if(pid2 > 0)
		global_var = 1;
	
	pid3 = getpid();

	cout << pid1 << pid2 << pid3 << global_var <<endl;
}

int main() {
	test1();
}

global_var = 10;
