#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer;

queue <pair<int, int>> q; // node_no, depth
int cost[10001];
vector<int> map[10001];
int input[10001];
int max_cost[10001];


void topology() {

	while(!q.empty()) {
		int cur = q.front().first;
		int cur_depth = q.front().second;
		q.pop();

		for(int i=0; i<map[cur].size(); i++) {
			int next = map[cur][i];
			/********여기가 문제였네요 *****/
			// depth 별로 최댓값을 구하는 게 아니라 노드별로 구했어야 합니다.
			max_cost[next] = max(max_cost[cur]+cost[next], max_cost[next]);
			if(--input[next] == 0)
				q.push(make_pair(next, cur_depth+1));
		}
	}
}

int main() {

	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		int cnt;
		scanf("%d %d", &cost[i], &cnt);
		while(cnt--) {
			int b;
			scanf("%d", &b);
			map[b].push_back(i);
			input[i]++;
		}	
	}

	for(int i=1; i<=n; i++) {
		if(input[i] == 0) {
			q.push(make_pair(i, 0));
			max_cost[i] = cost[i];
		}
	}

	topology();

	answer = 0;
	for(int i=0; i<=10001; i++) {
		answer = max(answer, max_cost[i]);
	}
	printf("%d\n", answer);

}