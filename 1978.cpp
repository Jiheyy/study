#include <iostream>
using namespace std;
int res;

bool isPrime(int n) { 
	if (n < 2) 
		return false; 
	for (int i = 2; i * i <= n; i++) { 
		if (n % i == 0) return false; 
	} 
	return true; 
}

int main() {
	int n;
	scanf("%d", &n);

	while(n--) {
		int no;
		scanf("%d", &no);
		if(isPrime(no)){
			res++;
		}
	}
	printf("%d\n", res);
}
