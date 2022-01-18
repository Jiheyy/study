#include <iostream>

// dp 재귀로 풀다가 중간에 안되면 걍 다 돌려보기
using namespace std;

long long dp[81];

int main() {
	int n;
	scanf("%d", &n);
	
	dp[0] = 4;
	dp[1] = 6;

	for (int i = 2; i < 81; ++i)
	{
		dp[i] = dp[i-2] + dp[i-1];
	}
	
	printf("%lld\n",dp[n-1]);
	

	return 0;
}