#include <iostream>
#include <algorithm>
using namespace std;

/*
한가지 방향만 구현할수 있다.
*/

int n, ret;
struct BOARD {
	int map[20][20];

	void rotate () {
		int temp[20][20];

		// rotate 90 degree clock wise
		// x, y 를 바꿔주고 법위를 바꿔주면 됩니다.
		for(int y=0; y<n; y++)
			for(int x=0; x<n; x++)
				temp[y][x] = map[n-x-1][y];

		// copy
		for(int y=0; y<n; y++)
			for(int x=0; x<n; x++)
				map[y][x] = temp[y][x];
	}

	int get_max() {
		int ret = 0;
		for(int y=0; y<n; y++)
			for(int x=0; x<n; x++)
				ret = max(ret, map[y][x]);

		return ret;
	}

	void up() {
		int temp[20][20] = {0,};

		for(int x=0; x<n; x++) {
			int flag = 0; 
			int target = -1;
			for(int y=0; y<n; y++) {
				if(map[y][x] == 0) continue;

				if(flag == 1 && map[y][x] == temp[target][x]) {
					temp[target][x] *= 2;
					flag = 0;
				}
				else {
					temp[++target][x] = map[y][x];
					flag = 1;
				}
			}
		}
		for(int y = 0; y<n; y++)
			for(int x = 0; x<n; x++)
				map[y][x] = temp[y][x];
	}
};

void dfs(BOARD cur, int count) {
	if(count == 5) {
		ret = max(ret, cur.get_max());
		return;
	}
	for(int dir = 0; dir <4; dir++) {
		BOARD next = cur;
		next.up();
		dfs(next, count+1);
		cur.rotate();
	}

} 

int main() {
	BOARD board;
	scanf("%d", &n);

	for(int y=0; y<n; y++)
		for(int x=0; x<n; x++)
			scanf("%d", &board.map[y][x]);
		
	dfs(board, 0);
	printf("%d\n", ret);

	return 0;
}
