#include <iostream>
#include <vector>
using namespace std;
int n, m;

bool visit[10] = {false,};
vector <int> choice;

void dfs(int cnt, int target) {
	if(cnt == target) {
		for(auto c: choice) {
			printf("%d ", c);
		}
		printf("\n");
		return;
	}
	for(int i=1; i<=n; i++) {
		if(visit[i] == true) continue;
		visit[i] = true;
		choice.push_back(i);
		dfs(cnt+1, target);
		visit[i] = false;
		choice.pop_back();
	}
}

int main() {

	scanf("%d %d", &n, &m);
	
	dfs(0, m);

	return 0;
}