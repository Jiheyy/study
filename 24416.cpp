#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int answer1 = 0;
int f[41];

int fib(int n) {
	if(n == 1 || n == 2) {
		answer++;
		return 1;
	}
	else 
		return (fib(n-1) + fib(n-2));
}

int fibonacci(int n) {
	f[1] = 1;
	f[2] = 1;

	for(int i=3; i<=n; i++) {
		f[i] = f[i-1] + f[i-2];
		answer1++;
	}
	return f[n];
}

int main() {
	int n;
	scanf("%d", &n);

	int ret = fib(n);
	int ret2 = fibonacci(n);
	printf("%d %d\n", answer, answer1);

}