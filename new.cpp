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

int arr[102][102];
SHARK shark[10404];

int my_x;


// up, down. right, left
// 이게 틀린 이유는 1번 상어가 이동해서 2번 상어 자리로 갔어도 2번 상어가 이동해서 그 자리에 없을 수 있다!
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};


void solve(int sum) {


	// map 초기화
	memset(arr, -1, sizeof(arr)); 

	// shark 배치
	for(int i=0; i<m; i++) {

		if(shark[i].y == -1)
			continue;

		int ny = shark[i].y;
		int nx = shark[i].x;


		// 빈칸일 경우
		if(arr[ny][nx] == -1) {
			arr[ny][nx] = i;
		}

		else {
			// 크기 비교
			int target_no = arr[ny][nx];
			// lose
			if(shark[target_no].size > shark[i].size) {
				shark[i].y = -1;
			}
			// win
			else if(shark[target_no].size < shark[i].size){
				arr[ny][nx] = i;
				shark[target_no].y = -1;
			}

		}
		
	}

	// move man
	my_x++;
	// x
	if(my_x == c) {
		answer = sum;
		return;
	}


	// find shark
	int target_no = -1;
	for(int i=0; i<r; i++) {
		// catch shark
		if(arr[i][my_x] != -1) {
			target_no = arr[i][my_x];

			sum += shark[target_no].size;

			arr[i][my_x] = -1;
			shark[target_no].y = -1;
			break;
		}
	}

	// shark move
	// get next move
	for(int i=0; i<m; i++) {
		// dead shark
		if(shark[i].y == -1)
			continue;
        
        // 초기 값
		int ny = shark[i].y;
		int nx = shark[i].x;
		int nd = shark[i].dir;
		int speed = shark[i].speed;

		// up, down
		if(nd <= 1) {

			
			while(speed--) {

				ny = ny + dy[nd];

				if(ny == -1) {
					nd = 1; // up -> down
					ny = 1; 
				}

				else if(ny == r) {
					nd = 0; // down -> up
					ny = r-2;
				}
			}
			
		}
		
		// right, left
		else {

			while(speed--) {

				nx = nx + dx[nd];

				if(nx == -1) {
					nd = 2; // left -> right
					nx = 1; 
				}

				else if(nx == c) {
					nd = 3;
					nx = c-2;
				}
			}

		}

		shark[i].y = ny;
		shark[i].x = nx;
		shark[i].dir = nd;
	}

	

	solve(sum);

}

int main() {

	scanf("%d %d %d", &r, &c, &m);

	my_x = -1;

	for(int i=0; i<m; i++) {
		int y, x, speed, dir, size;

		scanf("%d %d %d %d %d", &y, &x, &speed, &dir, &size);
		y--; x--; dir--;

		arr[y][x] = i;
		shark[i].y = y;
		shark[i].x = x;
		shark[i].dir = dir;
		shark[i].size = size;

		if(dir <= 1)
			speed %= ((r-1)*2);
		else
			speed %= ((c-1)*2);
		shark[i].speed = speed;
	}
	

	solve(0);

	printf("%d\n", answer);

	return 0;
}