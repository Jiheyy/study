#include <iostream>
#include <queue>
using namespace std;

struct CUR {
	int dir, y, x, cnt;
};
int n;
int map[301][301];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
int answer = 987654321;



void bfs(int y, int x) {
	queue <CUR> q;

	CUR start;
	start.y = y; start.x = x; start.cnt = 0;

	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(map[ny][nx] == false) {
			start.dir = i;
			break;
		}
	}
	q.push(start);

	while(!q.empty()) {

		CUR cur = q.front(); q.pop();

		cout << cur.y << cur.x << cur.dir <<endl;

		if(cur.y == n-1 && cur.x == n-1) {
			answer = min(answer, cur.cnt);
			break;
		}
		
		
		CUR next;
		next.y = cur.y + dy[cur.dir];
		next.x = cur.x + dx[cur.dir];
		next.cnt = cur.cnt+1;
		next.dir = cur.dir;

		if(next.y >= 0 && next.y < n && next.x >= 0 && next.x <=n)
			continue;

		while(true) {
			if(next.y >= 0 && next.y < n && next.x >= 0 && next.x <=n) continue;	
			if(map[next.y][next.x] == 0) break;
			next.dir = (next.dir+1) % 4;
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];
		}
			
		int side_dir = (next.dir + 3) %4;
		int side_y = next.y + dy[side_dir];
		int side_x = next.x + dx[side_dir];
		// 진행하려는 좌표 오른쪽에 벽이 있음
		if(map[side_y][side_x] == 1) {
			q.push(next);
		}


			if(next.y >= 0 && next.y < n && next.x >= 0 && next.x <=n 
				&& map[next.y][next.x] == false)
				q.push(next);
		}
		/*
		next.dir = (cur.dir+1)%4;
		next.y = cur.y + dy[next.dir];
		next.x = cur.x + dx[next.dir];
		next.cnt = cur.cnt+1;
		if(next.y >= 0 && next.y < n && next.x >= 0 && next.x <=n 
			&& map[next.y][next.x] == false)
			q.push(next);
	}*/
	}

}



int main() {
	int y, x;
	scanf("%d %d %d", &n, &y, &x);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	bfs(y, x);

	printf("%d\n", answer);



}