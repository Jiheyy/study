#include <iostream>
using namespace std;
int n, k;

int dp[31][31];

void dynamic() {

	for(int i=2; i<=n; i++) {
		for(int j=2; j<=i; j++){
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
}

int main() {

	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; i++)
		dp[i][1] = 1;

	dynamic();

	printf("%d\n", dp[n][k]);

}