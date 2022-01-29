#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int map[51][51];
int answer = 987654321;

int tmp[51][51];


struct TURN {
	int r, c,s;
};
vector <TURN> turn;

void copyMap() {
	for(int i=1; i<=n; i++)
		for(int  j=1; j<=m; j++)
			tmp[i][j] = map[i][j];
}

int count() {
	int ret = 987654321;
	for(int i=1; i<=n; i++) {
		int row = 0;
		for(int j=1; j<=m; j++) {
			row += tmp[i][j];
		}
		ret = min(ret, row);
	}

	return ret;
}
	
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void turnMap(int r, int c, int s) {

	//	가장 왼쪽 윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, c+s)인
	// 정사각형을 시계 방향으로 한 칸씩 돌린다는 의미이다.
	int sy = r-s;
	int sx = c-s;
	int ey = r+s;
	int ex = c+s;

	int cy = sy;
	int cx = sx;

	int dir = 0;
	int move_value = tmp[sy][sx];

	while(true) {
		if(sy >= ey || sx >= ex)
			break;

		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		// 밖으로 나올 경우
		if(ny > ey || nx > ex || ny < sy || nx < sx) {
			dir = (dir+1) % 4;
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}

		int save_value = tmp[ny][nx];
		tmp[ny][nx] = move_value;
		move_value = save_value;

		//printf("%d %d : %d -> %d %d\n", cy, cx, move_value, ny, nx);

		cy = ny;
		cx = nx;
		// 처음으로 돌아왔을 경우 sy ++ sx++, ex--, ey--
		if(cy == sy && cx == sx) {
			sy++; sx++; ey--; ex--;
			cy++; cx++;
			move_value = tmp[cy][cx];
			//break;
		}
	}

}

bool visit[10];
int choice[10];

void dfs(int cnt, int target) {
	if(cnt == target) {
		copyMap();
		for(int i=0; i<k; i++) {
			int no = choice[i];
			turnMap(turn[no].r, turn[no].c, turn[no].s);
		}
		answer = min(count(), answer);

		return;
	}
	for(int i=0; i<target; i++) {
		if(visit[i]) continue;
		visit[i] = true;
		choice[cnt] = i;
		dfs(cnt+1, target);
		visit[i] = false;
	}
}


int main() {

	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			scanf("%d", &map[i][j]);
		}

	int K = k;
	while(K--) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		TURN tmp;
		tmp.r = r; tmp.c = c; tmp.s = s;
		turn.push_back(tmp);
	}

	dfs(0,k);

	printf("%d\n", answer);


}