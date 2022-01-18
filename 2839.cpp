#include <iostream>
#include <algorithm>
using namespace std;
int n;


int main() {
	scanf("%d", &n);

    int dp[5001];
    for(int i=0; i<5001; i++)
        dp[i] = 987654321;

    dp[3] = 1;
    dp[5] = 1;

    for(int i=6; i<=n; i++) 
        dp[i] = min(dp[i-5]+1, dp[i-3]+1);



	if(dp[n] >= 987654321)
		printf("-1\n");
	else
		printf("%d\n", dp[n]);
}