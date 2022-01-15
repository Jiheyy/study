#include <iostream>

using namespace std;

bool solve(unsigned long long n, int d) {

	int check[10] = {0,};
	int last;
	while(n != 0) {
		last = n % d;
		if(check[last]++ > 1)
			return false;
		n = n/d;
	}
	if(last == 0) return false;

	for(int i=0; i<d; i++)
		if(check[i] != 1)
			return false;
	
	return true;
}

int main() {
	unsigned long long n;
	int d;
	scanf("%llu %d", &n, &d);
	bool res = true;

	if(n < 1 || n > 1000000000 || d < 2 || d > 10)
		return 0;
	int no = n+1;
	for(; no<1000000000; no++) {
		res = solve(no, d);
		if(res == true) break;
	}

	if(res == false)
		printf("-1\n");
	else
		printf("%d\n", no);
}