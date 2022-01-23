#include <iostream>
#include <vector>
using namespace std;

int n, m;
int answer = 987654321;

int arr[4010];
vector <int> friends[5000];
bool visit[5000];
int choice[5];


// new_no 가 choice 들과 친구인지 확인
bool checker(int cnt, int new_no) {

	if(cnt == 0)
		return true;

	int relations = 0;
	for(int i=0; i<friends[new_no].size(); i++) {
		int target = friends[new_no][i];
		if(cnt == 1) {
			if(target == choice[0])
				return true;
		}
		else if(cnt == 2) {
			if(target == choice[0]) 
				relations++;
			else if(target == choice[1])
				relations++;
			if(relations >= 2)
				return true;
		}
	}
	return false;
}

void dfs(int idx, int cnt, int target) {
	if(cnt == target) {
		int total = 0;
		for(int i=0; i<target; i++) {
			int no = choice[i];
			total += friends[no].size();
		}
		total -= 6;
		if(answer > total && total >= 0)
			answer = total;
		return;
	}

	for(int i=idx; i<=n; i++) {
		if(visit[i] == true) continue;
		if(checker(cnt, i) == false) 
			continue;
		visit[i] = true;
		choice[cnt] = i;
		dfs(i, cnt+1, target);
		visit[i] = false;
	}
}

int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		friends[a].push_back(b);
		friends[b].push_back(a);	
	}

	dfs(1, 0, 3);


	if(answer == 987654321)
		printf("-1");
	else
		printf("%d\n", answer);

}