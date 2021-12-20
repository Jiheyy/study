 #include <iostream>
 #include <algorithm>

 using namespace std;

 int n,k;
 int w[110];
 int v[110];
 int dp[110][100010];

 // dp
 int main() {

     scanf("%d %d", &n, &k);

     for(int i=1; i<=n; i++) {
         scanf("%d %d", &w[i], &v[i]);
     }

     for(int i=1; i<=n; i++) // item
         for(int j=0; j<=k; j++) { // weight
             if (j < w[i])
				dp[i][j] = dp[i-1][j];
			else
                 dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
         }


     for(int i=0; i<=n; i++) {
         for(int j=0; j<=k; j++)
             printf("%d ", dp[i][j]);
         printf("\n");
     }

     printf("%d\n", dp[n][k]);
 }
