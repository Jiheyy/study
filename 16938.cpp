#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, x;
long long l, r;
int arr[1000010];
bool visit[1000010];
int answer;


void dfs(int idx, int cnt, int target, int min_v, int max_v, long long sum) {

	if(cnt == target) {
		if(sum >= l && sum <= r && max_v-min_v >= x){
			answer++;
		}
		return;
	}

	for(int i=idx; i<n; i++) {
		if(visit[i]) continue;

		int next_min = min(min_v, arr[i]);
		int next_max = max(max_v, arr[i]);

		if(sum+arr[i] > r)
			continue;

		visit[i] = true;
		dfs(i, cnt+1, target, next_min, next_max, sum+arr[i]);
		visit[i] = false;
	}

}


int main() {
	scanf("%d %lld %lld %d", &n, &l, &r, &x);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);


	for(int i=2; i<=n; i++)
		dfs(0, 0, i, 987654321, 0, 0);

	printf("%d\n", answer);
}