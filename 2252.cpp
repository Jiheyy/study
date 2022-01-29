#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int visit[32001];
stack <int> answer;


void dfs(vector <vector <int>> &graph, int idx) {
	
	visit[idx] = 1; // 방문하고

	for(int i=0; i<graph[idx].size(); i++) {
		int des = graph[idx][i];
		if(visit[des] == 1) continue;
		dfs(graph, des);
	}
	answer.push(idx); // 새로운 타겟 집어넣고
}


int main() {
	scanf("%d %d", &n, &m);

	vector <vector <int>> graph (n+1);

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}


	for(int i=1; i<=n; i++)
		if(visit[i] == 0)
			dfs(graph, i);

	while(!answer.empty()) {
		printf("%d ", answer.top());
		answer.pop();
	}
}