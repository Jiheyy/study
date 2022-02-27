#include <iostream>
using namespace std;

long long dp[95];

void dynamic(int n) {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	
	for(int i=3; i <= n; i++)
		dp[i] = dp[i-1] + dp[i-2];
}

int main() {
	int n;
	scanf("%d", &n);

	dynamic(n);

	printf("%lld\n", dp[n]);

	return 0;
}