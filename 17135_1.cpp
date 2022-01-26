#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n, m, d, k;
int g[20][20];
int game[20][20];
int visited[20];
pair <int, int> e[300];
pair <int, int> enemy[300];
int enemyCnt;
bool die[200];
int ans, kill;


bool isAllDie() {
	for(int i=0; i<enemyCnt; i++)
		if(die[i] == false) return false;

	return true;
}

void attack() {

	vector <int> willDie = {};

	for(int i=0; i<m; i++) {
		if(visited[i]) {
			vector <pair<int, int>> tmp = {}; // 거리, 적 번호

			for(int j=0; j<enemyCnt; j++) {
				if(die[j]) continue; // 죽었는지 아닌지 확인한다.
				int distance = abs(enemy[j].first-n) + abs(enemy[j].second-i); // 거리를 구한다.
				if(distance > d) continue;
				tmp.push_back(make_pair(distance, j));
			}
			sort(tmp.begin(), tmp.end());
			if(tmp.size() == 0) continue;

			vector <pair<int, int>> tmp2; //(열, 적 번호)
			for(int j=0; j<tmp.size(); j++) {
				if(tmp[0].first == tmp[j].first) {
					tmp2.push_back(make_pair(enemy[tmp[j].second].second, tmp[j].second));
				}
			}
			sort(tmp2.begin(), tmp2.end());
			int idx = tmp2[0].second;
			willDie.push_back(idx);
		}
	}
	for(int i=0; i<willDie.size(); i++) {
		if(die[willDie[i]]) continue;
		kill++;
		die[willDie[i]] = true;
	}
}

void move() {
	for(int i=0; i<enemyCnt; i++) {
		if(die[i]) continue;
		int y = enemy[i].first;
		int x = enemy[i].second;
		y++;

		if(y == n) 
			die[i] = true;
		else {
			enemy[i].first = y;
			enemy[i].second = x;
		}
	}
}

void copy() {

	kill = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			game[i][j] = g[i][j];

	for(int i=0; i<enemyCnt; i++) {
		enemy[i].first = e[i].first;
		enemy[i].second = e[i].second;
	}
	memset(die, false, sizeof(die));
}


void dfs(int idx, int cnt, int target)
 {
 	// m열 중에서 3개를 선택
 	if(cnt == target) {
 		copy();
 		while(!isAllDie()) {
 			attack();
 			move();
 		}
 		ans = max(ans, kill);
 		return;
 	}

 	for(int i=idx; i<m; i++) {
 		if(visited[i]) continue;
 		visited[i] = true;
 		dfs(i, cnt+1, target);
 		visited[i] = false;
 	}
 }

int main() {
	scanf("%d %d %d", &n, &m, &d);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d", &g[i][j]);
			if(g[i][j] == 1)
				e[enemyCnt++] = make_pair(i, j);
		}

	dfs(0, 0, 3);

	printf("%d\n", ans);

}