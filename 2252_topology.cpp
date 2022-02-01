#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
vector <int> map[32001];
int input[32001];
vector <int> answer;
queue <int> q;

void topology() {

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for(int i=0; i<map[cur].size(); i++) {
			int next = map[cur][i];
			if(--input[next] == 0) // 진입차수가 0 이 되면 넣어준다.
				q.push(next);
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		input[b]++; // 진입차수
		map[a].push_back(b);
	}


	for(int i=1; i<=n; i++) {
		if(input[i] == 0) {
			q.push(i);
		}
	}
	topology();

	for(auto a: answer)
		printf("%d ", a);
}