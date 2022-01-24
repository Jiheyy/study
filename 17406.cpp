#include <iostream>
#include <vector>
using namespace std;

struct TURN {
	int r, c, s;
};

vector <TURN> turn;

int n, m, k;
int map[60][60];
bool visit[10];
int choice[10];
int copy_map[60][60];
int answer = 987654321;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void turn_box(TURN cmd){
	int sy = cmd.r - cmd.s;
	int sx = cmd.c - cmd.s;
	int ey = cmd.r + cmd.s;
	int ex = cmd.c + cmd.s;

	while(ey > sy && ex > sx) {
		int cy = sy;
		int cx = sx;
		int target = copy_map[cy][cx];
		int dir = 0;

		while(true) {

			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			// 처음위치로 돌아오게 된다면
			if(ny == sy && nx == sx){
				copy_map[ny][nx] = target;
				break;
			}
			
			if(nx < sx || ny < sy || nx > ex || ny > ey) {
				dir = (dir+1) % 4;
			 	ny = cy + dy[dir];
			 	nx = cx + dx[dir];
			}

			int tmp = copy_map[ny][nx];
			copy_map[ny][nx] = target;
			target = tmp;
			
			cy = ny; cx = nx;
		}
		sy++;
		sx++;
		ex--;
		ey--;

	}

	
}


void dfs(int cnt, int target) {

	if(cnt == target) {

		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				copy_map[i][j] = map[i][j];

		for(int i=0; i<target; i++){
			TURN cur = turn[choice[i]];
			turn_box(cur);
		}

		for(int i=1; i<=n; i++) {
			int row = 0;
			for(int j=1; j<=m; j++)
				row += copy_map[i][j];
			if(row < answer)
				answer = row;
		}
		return;
	}

	for(int i=0; i<target; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		choice[cnt] = i;
		dfs(cnt+1, target);
		visit[i] = false;
	}

}


int main() {
	scanf("%d %d %d", &n, &m, &k);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++){
			scanf("%d", &map[i][j]);
			copy_map[i][j] = map[i][j];
		}

	for(int i=0; i<k; i++) {
		int r, c, s;
		scanf("%d %d %d", &r, &c, &s);
		TURN tmp;
		tmp.r = r;
		tmp.c = c;
		tmp.s = s;
		turn.push_back(tmp);
	}

	dfs(0, k);
	printf("%d\n", answer);
}