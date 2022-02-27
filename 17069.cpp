#include <iostream>
#include <vector>

using namespace std;

unsigned long long answer;
int n;
int map[33][33];
unsigned long long dp[3][33][33];

int main() {

	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for(int i=2; i<=n; i++) {
		if(map[1][i] == 1) break;
		dp[0][1][i] = 1;
	}

	for (int r = 2; r <= n; r++)
    {
        for (int c = 2; c <= n; c++)
        {
            if (map[r][c] == 1)
                continue;

            dp[0][r][c] = dp[0][r][c - 1] + dp[2][r][c - 1];

            dp[1][r][c] = dp[1][r - 1][c] + dp[2][r - 1][c];

            if (map[r - 1][c] != 1 && map[r][c - 1] != 1)
                dp[2][r][c] = dp[0][r - 1][c - 1] + dp[1][r - 1][c - 1] + dp[2][r - 1][c - 1];
        }
    }

    for(int i=0; i<3; i++) {
    	answer += dp[i][n][n];
    }

	printf("%llu\n", answer);
}