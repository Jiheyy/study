#include <iostream>
#include <vector>
using namespace std;
int n, m;
int t;

// m 개중에서 n을 뽑기
unsigned long long choice(int n, int m) {
	unsigned long long a = 1;
	unsigned long long b = 1;

	for(int i=m; i>=(m-n+1); i--)
		a = a * i;

	for(int i=n; i>=1; i--)
		b = b*i;

	return a / b;
}

int main() {

	scanf("%d", &t);

	while(t--) {

		scanf("%d %d", &n, &m);

		if(m/2 < n) n = m-n;
		unsigned long long answer = choice(n, m);

		printf("%llu\n", answer);

	}

}