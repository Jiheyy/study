#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector <int> choice;

void dfs(int idx, int cnt, int target) {
	if(cnt == target) {
		//sort(choice.begin(), choice.end())
		for(auto c: choice)
			printf("%d ", c);
		printf("\n");
		return;
	}
	for(int i=idx; i<=n; i++) {
		choice.push_back(i);
		dfs(i, cnt+1, target);
		choice.pop_back();
	}
}

int main() {

	scanf("%d %d", &n, &m);
	
	dfs(1, 0, m);

	return 0;
}