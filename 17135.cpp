#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct POS {
	int y; int x;
};

int n, m, d;
int map[20][20];
int cmap[20][20];
int total_target, max_kill;

vector <POS> enemy;
vector <POS> arr;
bool visit[400];
POS choice[3];

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

//bool checker[400];

int find_target(POS cur){

	int min_idx = -1;
	int min_distance = 987654321;

	for(int i=0; i<enemy.size(); i++) {
		POS e = enemy[i];
		//printf("e.ingame %d\n", e.ingame);

		// 이미 죽은 아이
		if(e.y == -1) continue;

		int distance = abs(e.y - cur.y) + abs(e.x - cur.x);
		if(distance <= d) {
			if(min_distance > distance) {
				min_idx = i;
				min_distance = distance;
			}
			else if(min_distance == distance) {
				if (enemy[i].x < enemy[min_idx].x) {
					min_idx = i;
				}
			}
		}
	}
	return min_idx;
}



int move_target() {
	int ret = 0;
	int copy[20][20];

	memset(copy, 0, sizeof(copy));

	for(int i=0; i<enemy.size(); i++) {
		//if(checker[i]) continue;
		if(enemy[i].y == -1) continue;

		int y = enemy[i].y;
		int x = enemy[i].x;

		if(y+1 >= n) {
			enemy[i].y = -1;
			//checker[i] = true;
			ret++;
		}

		else {
			copy[y+1][x] = 1;
			enemy[i].y++;
		}

	}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cmap[i][j] = copy[i][j];

	return ret;

}

int attack() {

	int ret = 0;

	vector <int> targets;

	for(int i=0; i<total_target; i++) {
		int y = enemy[i].y;
		int x = enemy[i].x;
	}

}


void dfs(int idx, int cnt, int target)
 {
 	if(cnt == target) {
 		// copy!! 
 		for(int i=0; i<n; i++)
 			for(int j=0; j<m; j++)
 				cmap[i][j] = map[i][j];

 		int target_cnt = total_target;
 		int kill = 0;

 		while(target_cnt > 0) {

 			int cnt = attack();
 			kill += cnt;
 			target_cnt -= cnt;

 			target_cnt -= move_target();
 		}
	 	max_kill = max(kill, max_kill);
 		return;
 	}

 	for(int i=idx; i<int(arr.size()); i++) {
 		if(visit[i]) continue;
 		visit[i] = true;
 		choice[cnt] = arr[i];
 		dfs(i, cnt+1, target);
 		visit[i] = false;
 	}
 }

int main() {
	scanf("%d %d %d", &n, &m, &d);


	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) {
				total_target++;

				POS tmp; 
				tmp.y = i; tmp.x = j;
				enemy.push_back(tmp);
			}
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			POS tmp;
			tmp.y = i;
			tmp.x = j;
			arr.push_back(tmp);
		}

	dfs(0, 0, 3);

	printf("%d\n", max_kill);

	return 0;
}