#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int rot_size[] = {4, 2, 4, 4, 1};

struct CCTV {
	int y, x, no;
};
CCTV cctv[9];
int cctv_size;

int n, m;
int res = 987654321;
int map[10][10];

void update(int dir, CCTV cctv) {

	dir = (dir % 4);
	// 동남서북
	if(dir == 0) {
		for(int x=cctv.x+1; x<m; x++) {
			if(map[cctv.y][x] == 6)
				break;
			else 
				map[cctv.y][x] = -1;
		}
	}
	if(dir == 1) {
		for(int y=cctv.y+1; y<n; y++) {
			if(map[y][cctv.x] == 6)
				break;
			else 
				map[y][cctv.x] = -1;
		}
		
	}
	if(dir == 2) {
		for(int x=cctv.x-1; x>=0; x--) {
			if(map[cctv.y][x] == 6)
				break;
			else 
				map[cctv.y][x] = -1;
		}
	}
	if(dir == 3) {
		for(int y=cctv.y-1; y>=0; y--) {
			if(map[y][cctv.x] == 6)
				break;
			else 
				map[y][cctv.x] = -1;
		}
	}

}

void map_copy(int desc[][10], int src[][10]) {
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			desc[i][j] = src[i][j];
}


void DFS(int cctv_index) {

	if(cctv_index == cctv_size) {
		int candi = 0;
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++) {
				if(map[i][j] == 0)
					candi++;
			}
		}
		res = min(candi, res);
		return;
	}

	int backup[10][10] = {0,};
	int type = cctv[cctv_index].no;

	for(int dir=0; dir<rot_size[type]; dir++) {
		map_copy(backup, map);
		// 동남서북
		if(type == 0) {
			update(dir, cctv[cctv_index]);
		}
		if(type == 1) {
			update(dir, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
		}
		if(type == 2) {
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
		}
		if(type == 3) {
			update(dir, cctv[cctv_index]);
			update(dir+3, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
		}
		if(type == 4) {
			update(dir, cctv[cctv_index]);
			update(dir+1, cctv[cctv_index]);
			update(dir+2, cctv[cctv_index]);
			update(dir+3, cctv[cctv_index]);
		}
		DFS(cctv_index+1);
		map_copy(map, backup);
	}
}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0 && map[i][j] != 6) {
				cctv[cctv_size].y = i; 
				cctv[cctv_size].x = j;
				cctv[cctv_size].no = map[i][j]-1;
				cctv_size++;
			}
		}

	DFS(0);


	printf("%d\n", res);

}