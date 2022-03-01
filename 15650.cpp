#include <iostream>
#include <vector>
using namespace std;
int n, m;

bool visit[10] = {false,};

void dfs(int idx, int cnt, int target) {
	if(cnt == target) {
		for(int i=1; i<=n; i++) {
			if(visit[i])
				printf("%d ", i);
		}
		printf("\n");
		return;
	}
	for(int i=idx; i<=n; i++) {
		if(visit[i] == true) continue;
		visit[i] = true;
		dfs(i, cnt+1, target);
		visit[i] = false;
	}
}

int main() {

	scanf("%d %d", &n, &m);
	
	dfs(1, 0, m);

	return 0;
}