#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int dp[100001];

void dynamic() {
	dp[2] = 1; dp[4] = 2;
	dp[5] = 1; 

	for(int i=6; i<=100001; i++) {
		dp[i] = min(dp[i-5], dp[i-2]) +1;

	}
}

int main() {
	scanf("%d", &n);

	for(int i=0; i<=n; i++)
		dp[i] = 987654321;

	dynamic();

	for(int i=1; i<=100000; i++) {
		if(dp[i] == 987654321)
			printf("%d ",i);
	}

	int ret = dp[n];

	if(ret >= 987654321)
		printf("-1\n");
	else
		printf("%d\n", ret);

}