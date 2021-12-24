#include <iostream>
#include <vector>
using namespace std;

/* 
방향을 저장하는 map 이 필요
모래양을 저장하는 map이 필요
이동할때마다 퍼뜨러지는 비율을 저장하는 변수또한 필요
*/
int n;
int map[500][500];
int dir[500][500];

int c_y, c_x;
int res;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
const double ratios[] = {0.01, 0.01, 0.02, 0.07,0.07,0.02,0.10,0.10, 0.05};

const int blowY[4][10]={
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {1,1,0,0,0,0,-1,-1,-2,-1}
};
const int blowX[4][10]={
    {1,1,0,0,0,0,-1,-1,-2,-1},
    {-1,1,-2,-1,1,2,-1,1,0,0},
    {-1,-1,0,0,0,0,1,1,2,1},
    {-1,1,-2,-1,1,2,-1,1,0,0}
};

// n = 7
// 1 3 5 7

void get_dir() {
	bool visit[500][500] = {false};
	int x = 0;
	int y = 0;
	int d = 2;
	dir[y][x] = 2;
	visit[y][x] = true;

	while(true) {

		if(y == n/2 && x == n/2) {
			dir[y][x] = 2;
			break;
		}

		int n_y = y + dy[d];
		int n_x = x + dx[d];

		int a_y = n_y + dy[d];
		int a_x = n_x + dx[d];

		if(a_y < 0 || a_x < 0 || a_y >= n || a_x >= n || visit[a_y][a_x])
			d = (d+3) % 4;

		if(visit[n_y][n_x])
			continue;


		visit[n_y][n_x] = true;
		dir[n_y][n_x] = d;

		y = n_y;
		x = n_x;

	}	

}

void sand_move(int y_y, int y_x, int x_dir) {

	for(int i=0; i<10; i++) {
		int blow_y = blowY[x_dir][i];
		int blow_x = blowX[x_dir][i];

		int rat = ratios[i];

		int n_y = y_y + blow_y;
		int n_x = y_x + blow_x;

		if (n_y < 0 || n_x < 0 || n_y >= n || n_x >= n) 
			res += (map[y_y][y_x] * rat);
		else
			map[n_y][n_x] += (map[y_y][y_x] * rat);

		map[y_y][y_x] *= (1-rat);
	}

	// send left into a
	int a_y = y_y + dy[x_dir];
	int a_x = y_x + dx[x_dir];

	map[a_y][a_x] += map[y_y][y_x];
	map[y_y][y_x] = 0;
}

void solve() {

	int dir = 0;
	// 토네이도 이동
    for(double i=1.0;i<=n;i+=0.5){
        for(int j=0;j<(int)i;j++){
            c_y+=dy[dir%4];
            c_x+=dx[dir%4];

            ret+=sand_move(c_y,c_x,dir);
        }
        dir++;
    }

    return ret;

	int trial = 25;
	while(trial--) {
		// X
		if(c_y == 0 && c_x == 0)
			break;

		int d = dir[c_y][c_x];

		printf("%d %d %d\n", c_y, c_x, d);
		// Y
		int ny = c_y + dy[d];
		int nx = c_x + dx[d];

		sand_move(ny, nx, d);

		c_y = ny;
		c_x = nx;

	}
}


int main() {

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	// 토네이도 시작위치
	c_y = n/2;
	c_x = n/2;

	get_dir();

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			dir[i][j] = (dir[i][j] + 6) % 4;
			printf("%d ", dir[i][j]);
		}
		printf("\n");
	}

	solve();

	printf("%d\n", res);


	return 0;
}