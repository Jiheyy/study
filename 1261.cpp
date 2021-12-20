#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[110][110];
int visit[110][110];
queue <pair<int, int> > q;
int d_y[4] = {0, 1, 0, -1};
int d_x[4] = {1, 0, -1, 0};
int answer = 10000;

void BFS(int y, int x, int wall) {

	q.push(make_pair(y, x));

	while(!q.empty()) {
		tie(y, x) = q.front();
		//printf("%d %d %d\n", y, x, wall);
		q.pop();

		//if (y == n && x == m) {
		//	answer = min(visit[y][x], answer);
		//}

		for(int i=0; i<4; i++){
			int new_y = y + d_y[i];
			int new_x = x + d_x[i];

			//printf("%d %d\n", new_y, new_x);

			if(new_y < 1 || new_y > n || new_x < 1 || new_x > m) 
				continue;

			if(visit[new_y][new_x] > visit[y][x] + arr[new_y][new_x]) {
				visit[new_y][new_x] = visit[y][x] + arr[new_y][new_x];
				if(visit[new_y][new_x] < answer)
					q.push(make_pair(new_y, new_x));
			}
		}
	}
}


int main() {
	// x, y
	scanf("%d %d", &m, &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%1d", &arr[i][j]);

	// init visit as MAX
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			visit[i][j] = 10000;

	visit[1][1] = 0;

	BFS(1, 1, 0);
	printf("%d\n", visit[n][m]);
}
