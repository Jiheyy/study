#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct POS {
	int y, x, d;
};

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, m, res;
int map[51][51];
bool visit[51][51];


int solve(POS pos) {

	queue <POS> q;

	q.push(pos);
	
	while(!q.empty()) {

		POS cur = q.front(); q.pop();

		if(map[cur.y][cur.x] == 0) {
			map[cur.y][cur.x] = 2;
			res++;
		}
		
		POS n;
		for(int dir=0; dir<4; dir++) {
			n.d = (cur.d + 3 + (dir*3)) % 4;
			n.y = cur.y + dy[n.d];
			n.x = cur.x + dx[n.d];

			
			if(n.y < 0 || n.y >= N || n.x < 0 || n.x >= m
				|| map[n.y][n.x] != 0) {
				continue;
			}

			q.push(n);
			break;

		}

		if(q.empty()) {
			n.d = cur.d;
			n.y = cur.y + dy[(n.d + 2) % 4];
			n.x = cur.x + dx[(n.d + 2) % 4];

			if(n.y < 0 || n.y >= N || n.x < 0 || n.x >= m || map[n.y][n.x] == 1) {
				return res;
			}

			q.push(n);

		}
	}

	return res;

}





int main() {

	scanf("%d %d", &N, &m);

	POS pos;
	scanf("%d %d %d", &pos.y, &pos.x, &pos.d);

	for(int i=0; i<N; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);

	res = solve(pos);


	printf("%d\n", res);
	return 0;
}
