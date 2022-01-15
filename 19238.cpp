#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct CUS {
	int y, x, target_y, target_x;
};
struct D {
	int y, x, depth;
};

vector <CUS> cus;
int n, m;
int map[21][21];
int x, y, gas;
const int dx[] = {-1, 1, 0 ,0};
const int dy[] = {0, 0, -1, 1};


int drive(int y, int x, int ty, int tx) {
	queue <D> q;
	D d;
	d.y = y; d.x = x; d.depth = 0;
	q.push(d);

	bool visit[21][21] = {false,};

	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int depth = q.front().depth;
		q.pop();

		if(y == ty && x == tx) 
			return depth;

		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx]) continue;
			if(map[ny][nx] == 1) continue;
			visit[ny][nx] = true;
			D nd;
			nd.y = ny; nd.x = nx; nd.depth = depth+1;
			q.push(nd);
		}

	}
	return -1;

}

int solve() {
	int customer = m;

	while(customer--) {
		if(gas < 0)
			break;

		int len = 987654321;
		int target_no = 0;
		int cost;

		for(int i=0; i<m; i++) {
			if(cus[i].y == -1)
				continue;
			cost = drive(y, x, cus[i].y, cus[i].x);
			if(cost < 0) {
				customer++;
				break;
			}
			if(len > cost) {
				len = cost;
				target_no = i;
			}
			else if(len == cost) {
				if(cus[i].y == cus[target_no].y) {
					if(cus[i].x < cus[target_no].x)
						target_no = i;
				}
				else if(cus[i].y < cus[target_no].y)
					target_no = i;
			}
		}

		y = cus[target_no].y;
		x = cus[target_no].x;
		gas  -= len;
		if(gas < 0) {
			customer++;
			break;
		}

		cost = drive(y, x, cus[target_no].target_y, cus[target_no].target_x);
		if(cost < 0) {
			customer++;
			break;
		}
		y = cus[target_no].target_y;
		x = cus[target_no].target_x; 
		gas -= cost;
		if(gas < 0) {
			customer++;
			break;
		}

		gas += (cost * 2);

		map[cus[target_no].y][cus[target_no].x] = 0;
		cus[target_no].y = -1;
	}
	if(customer > 0)
		return -1;

	return gas;
}


int main() {
	scanf("%d %d %d", &n, &m, &gas);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	scanf("%d %d", &y, &x);
	y--; x--;

	for(int i=0; i<m; i++) {
		CUS tmp;
		scanf("%d %d %d %d", &tmp.y, &tmp.x, &tmp.target_y, &tmp.target_x);
		tmp.y--; tmp.x--; tmp.target_y--; tmp.target_x--;
		map[tmp.y][tmp.x] = i+2;
		cus.push_back(tmp);
	}

	int res = solve();
	printf("%d\n", res);
	return 0;
}