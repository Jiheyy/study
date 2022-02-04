#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int visit[2][500001];

int sum(int x) {
	return x * (x+1) / 2;
}

void bfs(int x, int target) {

	queue <pair <int, int>> q;
	q.push(make_pair(x, 0));
	visit[0][x] = 0;
	memset(visit, -1, sizeof(visit));

	while(!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		if(cur > 500000 || cur < 0) {
			continue;
		}

		if(visit[depth % 2][cur] != -1) {
			continue;
		}

		visit[depth % 2][cur] = depth;
		q.push({cur-1, depth+1});
		q.push({cur+1, depth+1});
		q.push({cur*2, depth+1});
	}

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	bfs(n, k);

	for(int i=0; i<500000; i++) {
		int nk = k + sum(i);
		if(nk > 500000) break;

		if(visit[i%2][nk] != -1 && visit[i%2][nk] <= i) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");

}