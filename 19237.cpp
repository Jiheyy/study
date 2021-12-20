#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct SHARK {
	int y, x, dir;
	int pri[4][4]; // up, down, left, right

};

struct BLOCK {
	int shark_no;
	int time; // time when its spread
};

// arr_size, shark_no, time_counter
int n, m, k;
int answer;
BLOCK arr[21][21];


const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

// sum : how many shark removed


void solve(SHARK shark[], int sum, int sec) {

	// update map -> 시간 정렬
	for(int i=0; i<n; i++)
		for(int j= 0; j<n; j++) {
			if(arr[i][j].time != 0) {
				arr[i][j].time--;
				if(arr[i][j].time == 0)
					arr[i][j].shark_no = -1;
			}	
		}

	if(sum == m-1) {
		answer = sec;
		return;
	}

	if(sec >= 1000) {
		answer = -1;
		return;
	}

	
	// spread
	for(int i=0; i<m; i++) {
		if (shark[i].y == -1)
			continue;

		// 마주쳤음. i 제거
		if(arr[shark[i].y][shark[i].x].time == k) {
			//printf("60 %d\n", i);
			shark[i].y = -1;
			shark[i].x = -1;
			shark[i].dir = -1;
			sum++;
			continue;
		}

		// 이동
		arr[shark[i].y][shark[i].x].shark_no = i;
		arr[shark[i].y][shark[i].x].time = k;
	}
	/*
	printf("--------\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) {
			printf("%d ", arr[i][j].shark_no);
		}
		printf("\n");
	}
	*/
	
	// move
	for(int s=0; s<m; s++) {

		// 죽은 상어 고려 x
		if(shark[s].y == -1)
			continue;

		bool is_exists = false;

		// 현재 위치	
		int cy = shark[s].y;
		int cx = shark[s].x;
		int cd = shark[s].dir;

		//printf("%d | %d %d %d\n", s, cy, cx, cd);

		int target_y, target_x, target_d;

		// turn
		for(int d=0; d<4; d++) {
			int nd = shark[s].pri[cd][d];
			int ny = cy + dy[nd];
			int nx = cx + dx[nd];

			//printf("%d | %d %d %d\n", s, ny, nx, nd);


			if(ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;


			// 냄새 없는 칸 존재
			//printf("%d\n", arr[ny][nx].shark_no);
			if(arr[ny][nx].shark_no == -1) {
				is_exists = true;
				target_y = ny;
				target_x = nx;
				target_d = nd;
				//printf("option 1! | %d [%d %d %d]\n", s, ny, nx, nd);
				break;
			}

			// 냄새 영향이 아직 있고
			// 본인의 냄새가 존재하는 위치를 저장, 우선순의에 의해 처음 값만 저장
			if(arr[ny][nx].shark_no == s && is_exists == false) {
				is_exists = true;

				target_y = ny;
				target_x = nx;
				target_d = nd;

			}

		}
		// 목적지 설정
		if (is_exists) {
			shark[s].y = target_y;
			shark[s].x = target_x;
			shark[s].dir = target_d;

		}
		
 	}
 	

 	//return;
	solve(shark, sum, sec+1);


}


int main() {

	scanf("%d %d %d", &n, &m, &k);


	SHARK shark[m];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			int shark_no;
			scanf("%d", &shark_no);
			shark_no--;
			arr[i][j].shark_no = shark_no;
			if(shark_no != -1) {
				shark[shark_no].y = i;
				shark[shark_no].x = j;
			}

		}



	for(int i=0; i<m ;i++) {
		scanf("%d", &shark[i].dir);
		shark[i].dir--;
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<4; j++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			a--; b--; c--; d--;
			shark[i].pri[j][0] = a;
			shark[i].pri[j][1] = b;
			shark[i].pri[j][2] = c;
			shark[i].pri[j][3] = d;
		}
	}

	solve(shark, 0, -1);

	printf("%d\n", answer);

	return 0;
}