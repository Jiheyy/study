#include <iostream>
using namespace std;
int dp[1000];


// 끝 부분을 fix 한 상태에서 확인하면 된다.


int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=4; i<=1000; i++) {
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}

	printf("%d\n", dp[n]);
	return 0;
}