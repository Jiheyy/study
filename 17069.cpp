#include <iostream>
#include <vector>

using namespace std;

const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};

struct POS {
	int y, x;
	int dir;
};
int answer;
int n;
int map[33][33];
bool visit[33][33];

void dfs(int y, int x, int dir) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if(ny == n && nx == n) {
		answer++;
		return;
	}

	if(ny > n || nx > n || ny <= 0 || nx <= 0 || map[ny][nx] == 1|| visit[ny][nx]) 
		return;

	visit[ny][nx] = true;
	//가로
	if(dir == 0) {
		if(map[ny][nx+1] != 1)
			dfs(ny, nx, 0);
		if(map[ny][nx+1] != 1 && map[ny+1][nx] != 1 && map[ny+1][nx+1] != 1)
			dfs(ny, nx, 2);
	}
	else if(dir == 1) {
		if(map[ny+1][nx] != 1)
			dfs(ny, nx, 1);
		if(map[ny][nx+1] != 1 && map[ny+1][nx] != 1 && map[ny+1][nx+1] != 1)
			dfs(ny, nx, 2);
	}
	else if(dir == 2) {
		if(map[ny][nx+1] != 1)
			dfs(ny, nx, 0);
		if(map[ny+1][nx] != 1)
			dfs(ny, nx, 1);
		if(map[ny][nx+1] != 1 && map[ny+1][nx] != 1 && map[ny+1][nx+1] != 1)
			dfs(ny, nx, 2);
	}
	visit[ny][nx] = false;
}

int main() {

	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(1, 1, 0);

	printf("%d\n", answer);
}