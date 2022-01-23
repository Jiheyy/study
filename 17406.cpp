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

void turn_box(int r, int c, int s){
	bool visit[n][m];
	memset(visit, false, sizeof(visit));
	int start_x = c-s;
	int start_y = r-s;
	int end_y = r+s;
	int end_x = c+s;
	int dir = 0;

	int cy = start_y; int cx = start_x;
	visit[cy][cx] = true;
	int cnt = 0;
	int last = copy_map[start_y+1][start_x];
	int value = copy_map[cy][cx];


	while(cnt < 4*s*c) {
		int ny = cy + dy[dir];
		int nx = cx + dx[dir];	

		if(ny < start_y || nx < start_x || ny > end_y || nx > end_x) {
			dir = (dir+1) % 4;
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}
		if(visit[ny][nx] == true) {
			copy_map[ny][nx] = last;
			dir = (dir+1) % 4;
			cy = cy + dy[dir];
			cx = cx + dx[dir];

			visit[cy][cx] = true;
			last = copy_map[cy+1][cx];

			value = copy_map[cy][cx];
			
			ny = cy + dy[dir];
			nx = cx + dx[dir];
		}

		visit[ny][nx] = true;

		int tmp = copy_map[ny][nx];
		copy_map[ny][nx] = value;
		cnt++;

		cy = ny;
		cx = nx;
		value = tmp;
	}
}


void dfs(int cnt, int target) {

	if(cnt == target) {

		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				copy_map[i][j] = map[i][j];

		for(int i=0; i<target; i++){
			TURN cur = turn[choice[i]];
			turn_box(cur.r, cur.c, cur.s);
			printf("-------%d----\n", cur.r);
			for(int y=1; y<=n; y++) {
				for(int x=1; x<=m; x++)
					printf("%d ", copy_map[y][x]);
				printf("\n");
			}

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