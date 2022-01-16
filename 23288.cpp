#include <iostream>
#include <queue>
using namespace std;
// 1, 2, 3, 4 동 서 북 남
// 0, 1, 2, 3 동 남 서 북
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int dice[7];

int n, m, score;
int map[21][21];
int k;
int x, y, dir;

void roll_dice(int d) {
	int d1, d2, d3, d4, d5, d6;

	d1 = dice[1], d2 = dice[2], d3 = dice[3];
	d4 = dice[4], d5 = dice[5], d6 = dice[6];
	// 동
	if(d == 0) {
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	// 남
	else if(d == 1) {
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
	}
	// 서
	else if(d== 2) {
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}
	// 북
	else if(d == 3) {
		dice[1] = d5;
        dice[2] = d1;
        dice[6] = d2;
        dice[5] = d6;
	}
}

int bfs (int y, int x, int b) {
	//printf("%d %d %d\n", y, x, b);
	int ret = 0;
	bool visit[21][21] = {false,};

	queue <pair<int, int>> q;
	q.push(make_pair(y,x));
	visit[y][x] = true;

	while(!q.empty()) {

		int cy = q.front().first;
		int cx = q.front().second;
		//printf("%d %d\n", cy, cx);
		q.pop();
		ret++;

		for(int i=0; i<4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if(ny < 1 || nx < 1 || ny > n || nx > m ||visit[ny][nx]) continue;
			if(map[ny][nx] != b) continue;

			visit[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}

	}
	//printf("ret : %d\n", ret);
	return ret * b;
}


void solve() {

	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if(ny < 1 || nx < 1 || ny > n || nx > m) {
		dir = (dir+2) % 4;
		ny = y + dy[dir];
		nx = x + dx[dir];
	}
	//printf("dir : %d", dir);
	roll_dice(dir);

	score += bfs(ny, nx, map[ny][nx]);
	
	int b = map[ny][nx];
	int a = dice[6];
	if (a > b)
		dir = (dir+1) % 4;
	else if(a < b)
		dir = (dir+3) % 4;

	y = ny;
	x = nx;

}


int main() {
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &map[i][j]);

	x = 1; y = 1; dir = 0;

	for(int i=1; i<7; i++)
		dice[i] = i;
	
	while(k--) {
		solve();
		//printf("%d\n", score);
	}

	printf("%d\n", score);

}
