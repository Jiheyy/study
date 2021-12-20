#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;


struct SHARK {
	int y, x, speed, dir, size;
};

// y, x
int r, c, m, answer;

int arr[101][101];
SHARK shark[10000];

int my_y, my_x;


// up, down. right, left
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};


// sum : how many shark u catch
void solve(int sum) {
	/*
	printf("--------------------\n");
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(arr[i][j] == -1)
				printf("- ");
			else
				printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	*/
	// move man
	my_x++;
	if(my_x >= c) {
		answer = sum;
		return;
	}


	// find shark
	int target_no = -1;
	for(int i=0; i<r; i++) {
		if(arr[i][my_x] != -1) {
			target_no = arr[i][my_x];
			break;
		}
	}

	if (target_no != -1) {
		//printf("catch!! %d\n", target_no);
		// catch sharkßß
		sum += shark[target_no].size;
		
		int t_y = shark[target_no].y;
		int t_x = shark[target_no].x;

		arr[t_y][t_x] = -1;
		shark[target_no].y = -1;
		shark[target_no].x = -1;
		shark[target_no].dir = -1;
		
	}

	// move shark
	for(int i=0; i<m; i++) {
		if(shark[i].y == -1)
			continue;


		int cy = shark[i].y;
		int cx = shark[i].x;
		int cd = shark[i].dir;
		int speed = shark[i].speed;

		int nd;
		int ny, nx;

		// up, down
		if(cd <= 1) {
			nx = cx;
			nd = cd;
			ny = cy;

			while(speed > 0) {

				ny = ny + dy[nd];

				if(ny < 0) {
					nd = 1; // up -> down
					ny = 1; 
				}

				else if(ny >= r) {
					nd = 0;
					ny = r-2;
				}
				speed--;
			}

			/*
			// change dir
			if((cy + (cd * speed)) / r != 0){
				// up
				if(cd == 0) {
					//down
					nd = 1;
				}
				// down
				else {
					// up
					nd = 0;
				}
			}
			//
			if(nd == 0) {
				ny = c - ((cy + (dy[cd] * shark[i].speed)) % r);
			}
			else {
				ny = (cy + (dy[cd] * shark[i].speed)) % r;
			}
			*/

		}
		
		// right, left
		else {
			ny = cy;
			nd = cd;
			nx = cx;

			while(speed > 0) {

				nx = nx + dx[nd];

				if(nx < 0) {
					nd = 2; // left -> right
					nx = 1; 
				}

				else if(nx >= c) {
					nd = 3;
					nx = c-2;
				}
				speed--;
			}

			//nx = cx + (cd * speed);

			// change dir
			/*
			if((cx + (dx[cd] * speed)) / c != 0){
				// ->
				if(cd == 2) {
					//<-
					nd = 3;
				}
				// <-
				else {
					// ->
					nd = 2;
				}
			}
			//
			if(nd == 3) {
				nx = c - ((cx + (dx[cd] * shark[i].speed)) % c);
			}
			else {
				nx = (cx + (dx[cd] * shark[i].speed)) % c;
			}
			*/

		}


		// printf("shark %d| %d, %d %d\n", i, ny, nx, shark[i].dir);

		// 기존 위치 삭제
		arr[cy][cx] = -1;
		// 새로운 정보 업데이트
		shark[i].y = ny;
		shark[i].x = nx;
		shark[i].dir = nd;

		// 이미 다른 상어 존재
		if(arr[ny][nx] != -1) {
			int target_no = arr[ny][nx];

			// win
			if(shark[target_no].size < shark[i].size) {
				// printf("1 eat! %d -> %d\n", target_no, i);
				arr[ny][nx] = i;
				shark[target_no].y = -1;
				shark[target_no].x = -1;
				shark[target_no].dir = -1;
			}
			// lose
			else if(shark[target_no].size > shark[i].size) {
				// printf("2 eat! %d -> %d\n", i, target_no);
				shark[i].y = -1;
				shark[i].x = -1;
				shark[i].dir = -1;
			}
		}
		// empty
		else {
			arr[ny][nx] = i;
		}

	}
	solve(sum);

}


int main(int argc, char ** argv) {

	scanf("%d %d %d", &r, &c, &m);

	memset(arr, -1, sizeof(arr));

	my_x = -1; my_y = -1;

	for(int i=0; i<m; i++) {
		int y, x, speed, dir, size;

		scanf("%d %d %d %d %d", &y, &x, &speed, &dir, &size);
		y--; x--; dir--;

		arr[y][x] = i;

		shark[i].y = y;
		shark[i].x = x;
		shark[i].speed = speed;
		shark[i].dir = dir;
		shark[i].size = size;
	}

	

	solve(0);

	printf("%d\n", answer);

	return 0;
}