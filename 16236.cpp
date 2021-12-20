#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct SHARK {
	int y, x, time;
};

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};


int n, type;
int arr[30][30];
bool visit[30][30];
SHARK shark;
int shark_eat, shark_size;


// 이중 while 이... 거슬리는데... 공간복잡도가 최대 20 만 되니까 가능한 알고인거지...

void BFS() {

	bool is_exists = true;

	while(is_exists) {

		is_exists = false;
		bool visit[30][30] = {false, };
		queue <SHARK> q;

		q.push(shark);
		visit[shark.y][shark.x] = true;

		SHARK target;
		// ??
		target.time = -1; // init value
		target.y = 30; // make it max, so that it can update target to cur

		while(!q.empty()) {

			SHARK cur = q.front(); 
			q.pop();

			//printf("%d %d\n", cur.y, cur.x);

			// queue 에 타임이 계속 업데이트 되니까 queue 에 있던 cur.time 과 시간 비교하면 된다.
			// 현재 시간과 타겟의 시간이 더 작을 경우 비교할 필요가 없음.
			if(target.time != -1 && target.time < cur.time)
				break;

			// eat
			if (arr[cur.y][cur.x] != 0 && arr[cur.y][cur.x] < shark_size) {
				is_exists = true;

				// compare target with cur

				// cur 내 위치
				// cur 가 x  가 더 작으면
				if(target.y > cur.y || (target.y == cur.y && target.x > cur.x) ) {
					target = cur;
				}
				
			}

			for(int i=0; i<4; i++) {
				SHARK next;
				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				next.time = cur.time + 1;

				if(next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) 
					continue;

				// if sharksize == arr value, can visit but can not eat
				// so that it can change cur position, therefore, put it in to queue
				if(visit[next.y][next.x] == false && arr[next.y][next.x] <= shark_size) {
					visit[next.y][next.x] = true;
					q.push(next);

				}
			}
		}
		// eat
		// printf("target.time = %d\n", target.time);
		if (is_exists) {
			arr[target.y][target.x] = 0;
			shark_eat++;
			shark = target;
			if(shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
		}
	}
}



int main(int argv, char ** argc) {

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			scanf("%1d", &arr[i][j]);

			if(arr[i][j] == 9){
				shark.y = i; shark.x = j; shark.time = 0;
				shark_size = 2; shark_eat = 0;
				arr[i][j] = 0;
			}
		}


	BFS();

	printf("%d\n", shark.time);


	return 0;
}