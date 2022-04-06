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
	
	printf("pid1 : %d pid2 : %d pid2 : %d global_var : %d\n", pid1, pid2, pid3, global_var);
}

int main() {
	test1();
}
int global_var = 10;
