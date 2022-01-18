#include <iostream>
#include <vector>
using namespace std;

int red[4][4];
int blue [6][4];
int green [6][4];
int n, t, x, y, score;

void gravity2(int y, int x, int arr[][4]) {

	arr[y][x] = 1;
	//arr[y][x+1] = 1;

	for(int x=0; x<4; x++) {
		bool exits = false;
		for(int y=4; y>=0; y--) {
			// -1, -2 는 이동을 안해도 댐
			if(arr[y][x] != 1)
				continue;

			int move = 0; // 바로 밑칸이랑 비교 움직일수 있다고 가정
			// end || not -

			while(true) {
				move++;
				if(arr[y+move][x] != 0 || arr[y+move][x+1] != 0|| y+move == 6) {
					move--;
					break;
				}
			}

			arr[y+move][x] = 2;
			arr[y+move][x+1] = 2;
			if(move != 0) 
				arr[y][x] = 0;
			
		}

	}

}


void gravity(int arr[][4]) {
	// gravity
	for(int x=0; x<4; x++) {
		bool exits = false;
		for(int y=4; y>=0; y--) {
			// -1, -2 는 이동을 안해도 댐
			if(arr[y][x] != 1)
				continue;

			int move = 0; // 바로 밑칸이랑 비교 움직일수 있다고 가정
			// end || not 

			while(true) {
				move++;
				if(arr[y+move][x] != 0 || y+move == 6) {
					move--;
					break;
				}
			}

			arr[y+move][x] = 2;
			if(move != 0)
				arr[y][x] = 0;
		}

	}
}

void move_down(int arr[][4], int row) {
	for(int y=row-1; y >= 0; y--)
		for(int x=0; x<4; x++) {
			arr[y+1][x] = arr[y][x];
			arr[y][x] = 0;
		}
}

void check_full(int arr[][4]) {

	bool loop = true;

	while(loop) {

		loop = false;
		for(int i=0; i<6; i++) {
			bool full_line = true;
			for(int j=0; j<4; j++)
				if(arr[i][j] == 0)
					full_line = false;
			if(full_line == true)  {
				loop = true;
				break;
			}

		}

		for(int i=5; i>=2; i--) {
			bool full = true;
			for(int j=0; j<4; j++) {
				if(arr[i][j] == 0) {
					full = false;
					break;
				}
			}
			if(full) {
				score++;
				move_down(arr, i);
			}
		}

		for(int i=0; i<2; i++)
			for(int j=0; j<4; j++)
				if(arr[i][j] == 2) {
					move_down(arr, 5);
				}

	}

}

void solve(int t, int y, int x) {
	// green
	if(t == 1) {
		green[0][x] = 1;
		blue[0][y] = 1;
		gravity(green);
		gravity(blue);
	}
	else if(t == 2) {
		blue[0][y] = 1;
		blue[1][y] = 1;
		gravity(blue);
		gravity2(0, x, green);

	}
	else if(t == 3) {
		green[0][x] = 1;
		green[1][x] = 1;
		gravity(green);
		gravity2(0, y, blue);
	}
	
	check_full(green);
	check_full(blue);
	
}

int count() {
	int ret = 0;

	for(int i=0; i<6; i++)
		for(int j=0; j<4; j++)
			if(blue[i][j] != 0)
				ret++;
			
	for(int i=0; i<6; i++)
		for(int j=0; j<4; j++)
			if(green[i][j] != 0)
				ret++;

	return ret;
}

int main() {
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d %d %d", &t, &x, &y);
		solve(t, x, y);
	}

	int res = count();
	printf("%d\n", score);
	printf("%d\n", res);

}