#include <iostream>
#include <cstring>
using namespace std;


long long dp[51][51][51];

long long w(int a, int b, int c) {

	if(a <= 0 || b <= 0 || c<=0)
		return 1;

	else if(dp[a][b][c] != 0) 
		return dp[a][b][c];

	else if(a>20 || b>20 || c> 20)
		return dp[20][20][20] = w(20, 20, 20);

	else if(a<b && b<c)
		return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

	else
		return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

}

int main() {

	int a, b, c;
	while(true) {
		scanf("%d %d %d", &a, &b, &c);

		if(a==-1 && b==-1 && c==-1) break;

		memset(dp, 0, sizeof(dp));

		printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
	}
}