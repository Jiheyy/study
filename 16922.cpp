#include <iostream>
using namespace std;

int no[4] = {1, 5, 10, 50};
bool visit[1001];
int n;
int answer;

// 중복 조합
// 4개(v)에서 n 개 뽑기
void dfs(int idx, int cnt, int sum) {
	if(cnt == n) {
		if(visit[sum] == false){
			visit[sum] = true;
			answer++;
		}
	return;

	}
	for(int i=idx; i<4; i++) {
		dfs(i, cnt+1, sum+no[i]);
	} 
}


int main() {

	scanf("%d", &n);

	dfs(0, 0, 0);
	printf("%d\n", answer);

	return 0;
}