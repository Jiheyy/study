#include <iostream>
#include <vector>
using namespace std;
// 오왼위아래
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

struct POS {
	int y, x, t;
};
int r, c, k, w;
int choco;
vector <POS> target; // 조사해야하는 칸
//vector <POS> wall; // 벽 위치
vector <POS> heater; // 온풍기 위치

int map[21][21];
bool wall[21][21][4]; // 왼 아래 오른 위

bool checker() {
	for(auto w: wall) {
		if(map[w.x][w.y] < k)
			return true;
	}
	// 중단
	return false;
}

bool check_wall(int cy, int, cx)



void blow(int idx) {
	bool visit[21][21] = {false};

	int dir = heater[idx].t;
	int cx = heater[idx].x;
	int cy = heater[idx].y;

	for(int value=5, cnt=0; value>=1; value--, cnt++) {
		int nx = cx + dx[dir];
		int ny = cy + dy[dir];
		printf("value : %d\n", value);
		//map[cx][cy] = value;
		//visit[cx][cy] = true;

		for(int i=0; i<cnt; i++) {
			// 위 아래 -> cy
			if(dir >= 1) {
				if(ny-i >= 1 && ny-i <= r && !visit[nx][ny-i]) {
					if(i == cnt-1) // coner
						if(check_wall(int cy, int cx, int ny-i, int nx, int dir, true)) continue;
					else
						 {
						 	if(wall[cy][cx][dir] == true) continue;

						 }
						if(check_wall(int cy, int cx, int cy-i, int cx, int dir, false)) continue;
					map[cx][cy-i] = value;
					visit[cx][cy-i] = true;
				}
				if(cy+i >= 1 && cy+i <= r && !visit[cx][cy+i]) {
					map[cx][cy+i] += value;
					visit[cx][cy+i] = true; 
				}
			}
			else {
				if(cx-i >= 1 && cx-i <= c && !visit[cx-i][cy]) {
					map[cx-i][cy] += value;
					visit[cx-i][cy] = true;
				}
				if(cx+i >= 1 && cx+i <= c && !visit[cx+i][cy]) {
					map[cx+i][cy] += value;
					visit[cx+i][cy] = true;
				}
			}

		}
		cx = nx; cy = ny;

	}
	/*
	printf("-------------\n");
	for(int i=1; i<r; i++) {
		for(int j=1; j<c; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/
	//exit(0);
}

void solve() {

	while(true) {

		//1.
		for(int i=0; i<heater.size(); i++) 
			blow(i);
		
		exit(0);
		// 2.
		// 3.
		// 4. 
		choco++;
		// 5. 
		if(checker() == false)
			break;
	}
}

int main() {
	scanf("%d %d %d", &r, &c, &k);

	for(int i=1; i<=r; i++) {
		for(int j=1; j<=c; j++) {
			int value;
			scanf("%d", &value);
			if(value != 0) {
				value--;
				POS tmp; tmp.x = i; tmp.y = j; tmp.t = value;
				if(value == 5)
					target.push_back(tmp);
				else
					heater.push_back(tmp);
			}
		}
	}
	scanf("%d", &w);

	for(int i=0; i<w; i++) {
		int y, x, t;
		scanf("%d %d %d", &x, &y, &t);
		/*
		0 : 오
		1 : 왼
		2 : 위
		3 : 아래 
		*/
		if(t == 0) {
			wall[x][y][1] = true;
			wall[x-1][y][0] = true;
		}
		else if(t == 1) {
			wall[x][y][3] = true;
			wall[x][y+1][2] = true;
		}


	}

	solve();

	printf("%d\n", choco);

}