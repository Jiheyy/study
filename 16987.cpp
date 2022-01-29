#include <iostream>
#include <vector>
using namespace std;

int n;
int weight[10];
int solid[10];
int answer;

	// 순열

void dfs(int idx) {
	if(idx == n) {
		int res = 0;
		for(int i=0; i<n; i++)
			if(solid[i] <= 0){
				res++;
			}

		answer = max(answer, res);
		return;
	}

	// 현재것이 깨졌다면 다음거
	if(solid[idx] <= 0) dfs(idx+1);
	else {
		bool crack = false;
		for(int i=0; i<n; i++) {
			if(i == idx || solid[i] <= 0) continue; // 현재거라면 혹은 이미 꺠졌더라면

			solid[idx] -= weight[i];
			solid[i] -= weight[idx];
			crack = true;

			dfs(idx+1);

			solid[idx] += weight[i];
			solid[i] += weight[idx];
		}
		// 깰것이 없다면 끝낸다.
		if(crack == false) {
			dfs(n);
		}
	}
}

int main() {

	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d %d", &solid[i], &weight[i]);
	}

	dfs(0);
	printf("%d\n", answer);
}