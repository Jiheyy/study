#include <iostream>
#include <algorithm>
using namespace std;

struct FISH {
	int y, x, dir;
};

const int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 }; 
const int dx[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };
int answer;


void solve(int arr[][4], FISH fish[], int shark_y, int shark_x, int sum) {

	//copy
	int tmp_arr[4][4];
	FISH tmp_fish[16];

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			tmp_arr[i][j] = arr[i][j];

	for(int i=0; i<16; i++)
		tmp_fish[i] = fish[i];

	// eat
	int fish_no = tmp_arr[shark_y][shark_x];
	int shark_dir = tmp_fish[fish_no].dir;

	tmp_arr[shark_y][shark_x] = -1;
	tmp_fish[fish_no].y = -1;
	tmp_fish[fish_no].x = -1;
	tmp_fish[fish_no].dir = -1;

	sum += (fish_no +1);

	answer = max(answer, sum);
	
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


		while(ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			//turn
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}
		
		int target = tmp_arr[ny][nx];

		//check wheather its empty
		if (target == -1) {
			tmp_arr[cy][cx] = -1;
			tmp_arr[ny][nx] = i;

			tmp_fish[i].y = ny; 
			tmp_fish[i].x = nx; 
			tmp_fish[i].dir = nd;
		}
		else {
			tmp_fish[i].y = ny; 
			tmp_fish[i].x = nx; 
			tmp_fish[i].dir = nd;

			tmp_fish[target].y = cy; 
			tmp_fish[target].x = cx;

			tmp_arr[cy][cx] = target;
			tmp_arr[ny][nx] = i;
		}
	}
	
	
	// shark move
	for(int i=1; i<4; i++) {
		int ny = shark_y + (dy[shark_dir] * i);
		int nx = shark_x + (dx[shark_dir] * i);

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			break;

		if(tmp_arr[ny][nx] != -1)
			solve(tmp_arr, tmp_fish, ny, nx, sum);
	}
	

}

int main() {

	FISH fish[16];

	int arr[4][4];

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);	
			a--; b--;
			fish[a].y = i; fish[a].x = j; fish[a].dir = b;
			arr[i][j] = a;
 		}

 	solve(arr, fish, 0, 0, 0);

 	printf("%d\n", answer);


	return 0;
}