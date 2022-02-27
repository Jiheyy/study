#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 반시계
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct FISH {
	int no; int dir; bool live;
	int x;
	int y;
};
vector <FISH> fish;
int s, m;
int shark_x, shark_y;

vector <int> map[5][5];
int smell[5][5];
int times;


vector<FISH> copy_fish() {
	vector <FISH> new_fish;

	for(auto f: fish) {
		if(f.live == false) continue;
		new_fish.push_back(f);
	}
	return new_fish;
}

void erase_ex(int y, int x, int no) {
	for(int i=0; i<map[y][x].size(); i++) {
		
		if(no == map[y][x][i]) {
			map[y][x].erase(map[y][x].begin() + i);
			return;
		}
	}
}


void move_fish() {

	for(int i=0; i<fish.size(); i++) {
		if(fish[i].live == false) continue;
		int cy = fish[i].y;
		int cx = fish[i].x;
		int dir = fish[i].dir;
		int ex_dir = dir;

		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		int trial = 0;

		while(ny <= 0 || nx <= 0 || ny > 4 || nx > 4 
			|| (ny == shark_y && nx == shark_x) 
			|| smell[ny][nx] != 0) {

			if(++trial >= 8) 
				break;

			// 	반시계 회전
			dir = (dir+7) % 8;
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}


		// 이동가능하다면
		if(trial < 8) {
			// update
			fish[i].y = ny;
			fish[i].x = nx;
			fish[i].dir = dir;
			erase_ex(cy, cx, i);
			map[ny][nx].push_back(i);
		}
	}
}

bool visit[5][5];
int max_dir[3];
int max_ate;
// dfs
void move_shark(int y, int x, int cnt, int ate, int dir[3]) {

	if(cnt == 3) {
		if(max_ate < ate) {
			max_ate = ate;
			max_dir[0] = dir[0]; max_dir[1] = dir[1]; max_dir[2] = dir[2];
		}
		else if(max_ate == ate) {
			string next = "";
			string cur_max = "";

			for(int i=0; i<3; i++) {
				next += (dir[i] + '0');
				cur_max += (max_dir[i] + '0');

				if(stoi(next) < stoi(cur_max)) {
					max_ate = ate;
					max_dir[0] = dir[0]; max_dir[1] = dir[1]; max_dir[2] = dir[2];
				}
			}
		}
		return;
	}

	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};

	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny <= 0 || nx <= 0 || ny > 4 || nx > 4 || visit[ny][nx])
			continue;

		visit[ny][nx] = true;
		dir[cnt] = i;
		move_shark(ny, nx, cnt+1, ate+map[ny][nx].size(), dir);
		visit[ny][nx] = false;
	}

}


void kill_fish() {
	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};
	int i=0;

	for(int i=0; i<3; i++) {
		int dir = max_dir[i];
		int ny = shark_y + dy[dir];
		int nx = shark_x + dx[dir];

		// 하나씩 죽이잠
		for(int j=0; j<map[ny][nx].size(); j++) {
			int no = map[ny][nx][j];
			fish[no].live = false;
			smell[ny][nx] = times; // 냄새를 남기자
		}
		map[ny][nx].clear();

		shark_y = ny; shark_x = nx;
	}
}

void remove_smell() {
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++) {
			if(times - smell[i][j] == 2) 
				smell[i][j] = 0;
		}
	}
}


void solve() {

	vector <FISH> new_fish = copy_fish();
	move_fish();

	max_ate = -1;
	int dir[3] = {0, 0, 0};

	move_shark(shark_y, shark_x, 0, 0, dir);

	kill_fish();

	remove_smell();
	
	int no = fish.size();
	for(int i=0; i<new_fish.size(); i++) {
		int y = new_fish[i].y;
		int x = new_fish[i].x;
		new_fish[i].no = no;
		fish.push_back(new_fish[i]);
		map[y][x].push_back(no);
		no++;
	}
}

int count() {
	int cnt = 0;
	for(auto f: fish)
		if(f.live) cnt++;

	return cnt;
}

int main() {

	scanf("%d %d", &m, &s);

	for(int i=0; i<m; i++) {
		FISH tmp;
		tmp.no = i; tmp.live = true;
		scanf("%d %d %d", &tmp.y, &tmp.x, &tmp.dir);
		tmp.dir--;
		fish.push_back(tmp);
		map[tmp.y][tmp.x].push_back(i);
	}
	scanf("%d %d", &shark_y, &shark_x);

	while(s--) {
		times++;
		solve();
	}

	printf("%d\n", count());

	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			printf("%lu ", map[i][j].size());
		}
		printf("\n");
	}
	return 0;
}