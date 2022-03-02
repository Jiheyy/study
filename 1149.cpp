#include <iostream>
#include <vector>
using namespace std;
int n;
int map[1000][3];
int min_cost = 987654321;


void dfs(int ex_choice, int cost, int cnt, int target) {

	if(cnt == target) {
		min_cost = min(cost, min_cost);
		return;
	}

	for(int i=0; i<3; i++) {
		if(cost+map[cnt][i] > min_cost) continue;
		if(ex_choice == i) continue;
		dfs(i, cost+map[cnt][i], cnt+1, target);

	}
}




int main() {

	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);
	}

	dfs(-1, 0, 0, n);

	printf("%d\n", min_cost);



}