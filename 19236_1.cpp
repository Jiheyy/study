#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct FISH {
	int y, x, dir;

};

int answer;


const int dy[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
const int dx[8] = {0, -1, -1, -1, 0, +1, +1, +1};

void solve (int arr[][4], FISH fish[], int shark_y, int shark_x, int sum) {

	// copy
	int tmp_arr[4][4]; 
	FISH tmp_fish[16];

	memcpy(tmp_arr, arr, sizeof(tmp_arr));
	memcpy(tmp_fish, fish, sizeof(tmp_fish));

	printf("27\n");
	
	// shark_eat
	int fish_no = tmp_arr[shark_y][shark_x];
	int shark_dir = tmp_fish[fish_no].dir;

	tmp_arr[shark_y][shark_x] = -1;
	tmp_fish[fish_no].y = -1;
	tmp_fish[fish_no].x = -1;
	tmp_fish[fish_no].dir = -1;

	sum += (fish_no+1);
	answer = max(sum, answer);

	// fish move
	for(int i=0; i<16; i++) {
		if(tmp_fish[i].y == -1)
			continue;

		int cy = tmp_fish[i].y;
		int cx = tmp_fish[i].x;
		int cd = tmp_fish[i].dir;

		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd;

		while(ny < 0 || ny >=4 || nx < 0|| nx >=4 || (ny == shark_y && nx == shark_x)) {
			nd = (nd+1) %8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}

		if(tmp_arr[ny][nx] == -1) {
			tmp_arr[ny][nx] = i;
			tmp_arr[cy][cx] = -1;

			tmp_fish[i].y = ny;
			tmp_fish[i].x = nx;
			tmp_fish[i].dir = nd;
		}
		else {
			int target = tmp_arr[ny][nx];
			tmp_arr[ny][nx] = i;
			tmp_arr[cy][cx] = target;

			tmp_fish[i].y = ny;
			tmp_fish[i].x = nx;
			tmp_fish[i].dir = nd;

			tmp_fish[target].y = cy;
			tmp_fish[target].x = cx;
		}
	}



	// shark_move
	for(int i=0; i<=3; i++) {
		int ny = shark_y + (dy[shark_dir] * i);
		int nx = shark_x + (dx[shark_dir] * i);

		if(ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			break;
		if(tmp_arr[ny][nx] != -1)
			solve(tmp_arr, tmp_fish, ny, nx, sum);
	}
		

}

int main(int argv, char ** argc) {

	int arr[4][4];
	FISH fish[16];

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--; b--;
			fish[a].y = i;
			fish[a].x  = j;
			fish[a].dir = b;
			arr[i][j] = a;
		}

	solve(arr, fish, 0, 0, 0);

	printf("%d\n", answer);

	return 0;
}
