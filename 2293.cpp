#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[100];
int answer;

void dfs(int idx, int cur, int target) {
	if(cur == target) {
		answer++;
		return;
	}

	for(int i=idx; i<n; i++) {
		if(cur + arr[i] > target) continue;
		dfs(i, cur+arr[i], target);
	}
}

int main() {

	scanf("%d %d", &n, &k);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	dfs(0, 0, k);
	printf("%d\n", answer);
}