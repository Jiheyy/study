#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int dp[5001];
    // memeset 의 경우 0 으로 초기화 할때는 유용한 선택이 될 수 있지만 그 외의 경우에는 얘기 가 다르다.
    // 메모리 블록을 채우는 것이기때문에 0 이 아닌 다른 값으로 메모리를 초기화하고자 할때 문제가 발생할 수 있다.
    // for 로 초기화를 해주자
    for(int i=0; i<5001; i++)
        dp[i] = 987654321;
    

    int n;
    scanf("%d", &n);

    dp[3] = 1;
    dp[5] = 1;
    
    for(int i=6; i<=n; i++)
        dp[i] = min(dp[i-3]+1, dp[i-5]+1);


    if(dp[n] >= 987654321)
        printf("-1\n");
    else
        printf("%d\n", dp[n]);
}