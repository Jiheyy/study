#include <iostream>
#include <vector>
#include <map>
using namespace std;
	
int n, m;
int answer; 
int arr[210];
int choice[5];
bool visit[210];

vector <int> cant[210];

bool checker(int cnt, int new_no) {

	if(cnt == 0)
		return true;

	for(int i=0; i<cant[new_no].size(); i++) {
		int a = cant[new_no][i];
		if(cnt == 1) {
			if(choice[0] == a)
				return false;
		}
		else if(cnt == 2) {
			if(choice[0] == a || choice[1] == a)
				return false;
		}

	}
	return true;


void dfs(int cnt, int idx, int target) {
	if(cnt == target) {	
		answer++;
		return;
	}

	for(int i=idx; i<=n; i++) {
		if(visit[i]) continue;
		if(checker(cnt, arr[i]) == false)
			continue;
		visit[i] = true;
		choice[cnt] = arr[i];
		dfs(cnt+1, i, target);
		visit[i] = false;
		choice[cnt] = 0;
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for(int i=1; i<=n; i++) {
		arr[i] = i;
	}

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cant[a].push_back(b);
		cant[b].push_back(a);
	}


	dfs(0, 1, 3);


	printf("%d\n", answer);



	return 0;
}