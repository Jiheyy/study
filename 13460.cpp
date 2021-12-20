#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


/*
빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 
빨간 구슬을 구멍을 통해 빼내는 게임이다.

파란 구슬이 구멍에 들어가면 안 된다.
중력을 이용해서 이리 저리 굴려야 한다. 
왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기

공은 동시에 움직인다. 
빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다.

기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.


최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오. (BFS)
*/
struct INFO {
	int by, bx, ry, rx; // 위치
	int cnt;
};

int n,m;
INFO start;
int answer = -1;
string map[11];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};



void BFS() {
	
	bool visit[10][10][10][10] = { false };

	queue <INFO> q;
	q.push(start);
	visit[start.rx][start.ry][start.bx][start.by] = true;


	while(!q.empty()) {
		INFO cur = q.front(); 	q.pop();

		if(cur.cnt > 10)
			return;
		if(map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O') {
			answer = cur.cnt;
			return;
		}

		//왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기
		for(int i=0; i<4; i++) {
			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;
			// 	빨간공이 벽에 닿을때까지 간다.
			while(1) {
				// .
				if (map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O') {
					next_rx += dx[i];
					next_ry += dy[i];
				}
				// # or O
				else {
					// #
					if(map[next_rx][next_ry] == '#') {
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
					break;
				}
			}

			// 	파란공이 벽에 닿을때까지 간다.
			while(1) {
				// .
				if (map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O') {
					next_bx += dx[i];
					next_by += dy[i];
				}
				// # or O
				else {
					// #
					if(map[next_bx][next_by] == '#') {
						next_bx -= dx[i];
						next_by -= dy[i];
					}
					break;
				}
			}
			// 둘이 겹쳤을 경우 더 많이 움직인쪽을 하나 백한다. 
			if(next_rx == next_bx && next_ry == next_by) {
				if(map[next_rx][next_ry] != 'O') {
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);

					if (red_dist >= blue_dist) {
						next_rx -= dx[i];
						next_ry -= dy[i];
					}
					else {
						next_bx -= dx[i];
						next_by -= dy[i];
					}
				}
			}
			// 방문확인
			if(visit[next_rx][next_ry][next_bx][next_by] == false) {
				visit[next_rx][next_ry][next_bx][next_by] = true;
				INFO next;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.cnt = cur.cnt + 1;
				q.push(next);
			}
		}
	}

}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++) {
		cin >> map[i];
		for (int j=0; j<m; j++) {
			if(map[i][j] == 'R') {
				start.rx = i;
				start.ry = j;
			}
			if(map[i][j] == 'B') {
				start.bx = i;
				start.by = j;
			}
		}
		
	}
	start.cnt = 0;
	BFS();
	printf("%d\n", answer);
	return 0;
}