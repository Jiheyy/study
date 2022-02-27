#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
// 반시계 d r u l
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int map[51][51];
int x[2];
int y[2];
int r, c, t;

struct SPREAD {
	int y, x, value;
	vector <pair <int, int>> next;
};

int count(int r, int c) {
	int ret = 0;

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(map[i][j] != -1)
				ret += map[i][j];
	return ret;
}

void move_ele(int ny, int nx, int cy, int cx) {
	if(map[cy][cx] == -1)
		map[ny][nx] = 0;
	else if(map[ny][nx] == -1)
		return;
	else {
		printf("move %d %d into %d %d : %d\n", cy, cx, ny, nx, map[cy][cx]);
		map[ny][nx] = map[cy][cx];
	}
}

void uwind() {
	// 아래로
	for(int i=r/2-1; i>=0; i--) 
		move_ele(i+1, 0, i, 0);
	// 왼쪽으로
	
	for(int i=1; i<c; i++) {
		move_ele(0, i-1, 0, i);
	}

	// 위쪽로
	for(int i=1; i<r/2; i++)
		move_ele(i-1, c-1, i, c-1);
	
	// 오른쪽으로
	for(int i=c-1; i>=1; i--)
		move_ele(r/2-1, i, r/2-1, i-1);
	
}

void dwind() {

	// 오른쪽으로
	for(int i=c-1; i>=1; i--){
		printf("right ");
		move_ele(r/2, i, r/2, i-1);
	}
	// 아래로
	for(int i=r-2; i>=r/2+1; i--) {
		printf("down ");
		move_ele(i, c-1, i-1, c-1);
	}
	/*
	// 왼쪽으로
	for(int i=1; i<c; i++) {
		printf("left ");
		move_ele(r-1, i-1, r-1, i);
	}

	// 위쪽로
	for(int i=r/2; i>=r; i++) {
		printf("up ");
		move_ele(i-1, 0, i, 0);
	}
	*/
	
	
}

void solve() {
	// 1. 확산
	// 확산 할 리스트 구하기
	vector <SPREAD> spread;

	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(map[i][j] == -1 || map[i][j] == 0) continue;

			SPREAD sand;
			sand.y = i; sand.x = j;
			sand.value = map[i][j];
			sand.next.clear();
		
			for(int d=0; d<4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];

				if(ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == -1)
					continue;
				sand.next.push_back(make_pair(ny, nx));
			}
			spread.push_back(sand);
		}

	}


	// 증감
	int tmp[51][51];
	memset(tmp, 0, sizeof(tmp));

	for(auto s : spread) {
		tmp[s.y][s.x] -= int(int(s.value / 5) * int(s.next.size()));

		for(auto n : s.next) {
			tmp[n.first][n.second] += int(s.value/5);
		}
	}

	// update
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			map[i][j] += tmp[i][j];


	// 2. 공기청정기가 작동한다.
	uwind();
	dwind();
	printf("-------------------\n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	/*
	// 위쪽
	int dir = 2; // up
	int sy = mid-1; int sx = 0; // 초기 위치
	int cy = sy; int cx = sx;

	while(true) {
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		if(ny < 0 || nx < 0 || ny >= mid || nx >= c) {
			dir = (dir+3)%4;
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}
	
		if(map[ny][nx] == -1)
			map[cy][cx] = 0;

		else if(map[cy][cx] != -1)
			map[cy][cx] = map[ny][nx];

		if(sy == ny && sx == nx) break;

		cy = ny; cx = nx;

	}
	
	// 아래쪽 -> 시계
	dir = 0;
	sy = mid; sx = 0;
	cy = sy; cx = sx;

	while(true) {
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];

		if(ny < mid || nx < 0 || ny >=r || nx >= c) {
			dir = (dir+1)%4;
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}
	
		if(map[ny][nx] == -1)
			map[cy][cx] = 0;

		else if(map[cy][cx] != -1)
			map[cy][cx] = map[ny][nx];

		if(sy == ny && sx == nx) break;

		cy = ny; cx = nx;
	}
	*/
	
}


int main() {

	scanf("%d %d %d", &r, &c, &t);

	int idx = 0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == -1) {
				y[idx] = i;
				x[idx] = j;
				idx++;
			}
		}

	while(t--) {
		solve();
	}

	int answer = count(r, c);
	printf("%d\n", answer);

}
