#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


// 이게 왜 반시계..?

const int dy[8] = { -1, -1, 0, +1, +1, +1, 0, -1 }; 
const int dx[8] = { 0, -1, -1, -1, 0, +1, +1, +1 };


struct FISH {
	int dir, y, x;
};

int answer;

// fish start with 1 not 0
void solve(int board[][4], FISH fish[], int shark_y, int shark_x, int sum) {

	// copy
	int candi_board[4][4];
	FISH candi_fish[16];

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			candi_board[i][j] = board[i][j];

	for(int i=0; i<16; i++)
		candi_fish[i] = fish[i];

	//eat
	int fish_no = candi_board[shark_y][shark_x];
	int shark_dir = candi_fish[fish_no].dir;

	candi_fish[fish_no].dir = -1;
	candi_fish[fish_no].y = -1;
	candi_fish[fish_no].x = -1;
	candi_board[shark_y][shark_x] = -1;

	sum += (fish_no+1);

	answer = max(answer, sum);
	

	//fish move
	for(int f=0; f<16; f++) {
		if (candi_fish[f].dir == -1)
			continue;

		int cy = candi_fish[f].y;
		int cx = candi_fish[f].x;
		int cd = candi_fish[f].dir;


		// since it can move one block
		int ny = cy + dy[cd];
		int nx = cx + dx[cd];
		int nd = cd;

		//check wheather the point is valid
		// if not turn

		while(ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || (ny == shark_y && nx == shark_x)) {
			//turn
			nd = (nd + 1) % 8;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}
		
		// check next target to move
		// if it's not empty. exchange c with n
		if(candi_board[ny][nx] != -1) {
			int target = candi_board[ny][nx];
			
			candi_fish[target].y = cy;
			candi_fish[target].x = cx;

			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			candi_board[ny][nx] = f;
			candi_board[cy][cx] = target; 
		}

		// if it empty
		else {
			candi_fish[f].y = ny;
			candi_fish[f].x = nx;
			candi_fish[f].dir = nd;

			candi_board[cy][cx] = -1;
			candi_board[ny][nx] = f;

		}
	}


	// shark move
	for(int i=1; i<=3; i++) {
		int ny = shark_y + (dy[shark_dir] * i);
		int nx = shark_x + (dx[shark_dir] * i);

		if(ny < 0 || ny >= 4 || nx < 0|| nx >= 4)
			break;

		// if it;s not empty
		if(candi_board[ny][nx] != -1) {
			solve(candi_board, candi_fish, ny, nx, sum);
		}
	}
}


int main(int argv, char** argc) {

	FISH fish[16];
	int board[4][4];

	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;

			fish[a].y = i;
			fish[a].x = j;
			fish[a].dir = b;
			board[i][j] = a;

		}
	}

	// board, fish, shark_y, shark_x, sum
	solve(board, fish, 0, 0, 0);

	printf("%d\n", answer);

	return 0;
}




/*
이런식으로 저장하고
매번 돌리기 좀 그런뎀...
sort

*/
