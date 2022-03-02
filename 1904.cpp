#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001];

void DP(long long n) {
	dp[n] = (dp[n-1] + dp[n-2]) % 15746;
}


int main() {
	long long n;
	scanf("%lld", &n);

	dp[1] = 1; dp[2] = 2; dp[3] = 3;

	for(long long i=3; i<=n; i++)
		DP(i);

	printf("%lld\n",dp[n]);

}