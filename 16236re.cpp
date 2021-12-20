#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct SHARK {
	int y, x, t;
};


const int dx[4] =  {-1, 1, 0, 0};
const int dy[4] =  {0, 0, -1, 1};

SHARK shark;
int shark_size, shark_eat;

int n;
int arr[30][30];




void BFS() {

	bool is_exists = true;

	while(is_exists) {
		queue <SHARK> q;
		is_exists = false;
		int visit[30][30] = {false, };

		q.push(shark);
		visit[shark.y][shark.x] = true;

		SHARK target;
		target.t = -1;
		target.y = 30;

		while (!q.empty()) {
			SHARK cur = q.front();
			q.pop();


			if(target.t != -1 && target.t < cur.t)
				break;

			// compare target with cur
			if(arr[cur.y][cur.x] != 0 && arr[cur.y][cur.x] < shark_size) {
				is_exists = true;
				if(cur.y < target.y || (cur.y == target.y && cur.x < target.x)) {
					target = cur;
				}
			}


			for(int i=0; i<4; i++) {
				SHARK next;
				next.y = cur.y + dy[i];
				next.x = cur.x + dx[i];
				next.t = cur.t + 1;

				if(next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
					continue;

				if(visit[next.y][next.x] == false && arr[next.y][next.x] <= shark_size) {
					visit[next.y][next.x] = true;
					q.push(next);
				}
			}
		}
		if (is_exists) {
			shark_eat++;
			shark = target;
			if(shark_eat == shark_size) {
				shark_size++;
				shark_eat = 0;
			}
			arr[shark.y][shark.x] = 0;
		}
 	}


}


int main(int argv, char ** argc) {

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			scanf("%1d", &arr[i][j]);

			if(arr[i][j] == 9) {
				shark.y = i;
				shark.x = j;
				shark.t = 0;

				shark_size = 2; shark_eat = 0;

				arr[i][j] = 0;
			}

		}

	BFS();

	printf("%d\n", shark.t);

	return 0;
}