#include <iostream>

using namespace std;

int n, ret;
int map[501][501];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};
const int ratios[9] = {1,1,2,2,7,7,10,10,5};

const int blowY[4][10] = {
	{-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
	{-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
	{1, -1, 2, -2, 1, -1, 1, -1, 0, 0},
	{1, 1, 0, 0, 0, 0, -1, -1, -2, -1}
};

const int blowX[4][10] = {
	{1, 1, 0, 0, 0, 0, -1, -1, -2, -1},
	{-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
	{-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
	{-1, 1, -2, 2, -1, 1, -1, 1, 0, 0}

};



void blowSand(int y, int x, int dir) {

	// 위치 y
	int init = map[y][x];

	// check all spaces
	for(int i=0; i<10; i++) {
		int sand;

		if(i != 9) {
			sand = init*ratios[i]/100; // 옮길 부분
			map[y][x] -= sand;
		}
		else
			sand = map[y][x];

		int by = y + blowY[dir][i];
		int bx = x + blowX[dir][i];


		// 밖으로 나갔을 경우
		if(by < 0 || bx < 0 || by >=n || bx >= n) {
			ret += sand;
			continue;
		}
		else
			map[by][bx] += sand;

	}
	map[y][x] = 0;

}

void solve(int y, int x, int dir, int move_cnt) {

	// 진행방향
	while(1) {
		for(int i=0; i<2; i++) {
			for(int j=0; j<move_cnt; j++) {
				y += dy[dir % 4];
				x += dx[dir % 4];

				blowSand(y, x, dir%4);

				if(y == 0 && x == 0)
					return;
			} 
			dir++;
		} 
		move_cnt++;
	}


}

int main() {

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	solve(n/2, n/2, 0, 1);

	printf("%d\n", ret);
	
	return 0;
}
