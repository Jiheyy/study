#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, q;
int bigN;
int map[65][65];
bool visit[65][65] = {false};

queue <pair <int, int>> adj;

vector <int> l;

int BFS(int y, int x) {

	int dimension = 0;

	adj.push(make_pair(y,x));
	visit[y][x] = true;

	while(!adj.empty()) {
		int y = adj.front().first;
		int x = adj.front().second;
		adj.pop();
		dimension++;

		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || ny >= bigN || nx < 0 || nx >= bigN || visit[ny][nx]) continue;

			if(map[ny][nx] > 0) {
				adj.push(make_pair(ny, nx));
				visit[ny][nx] = true;
			}
		}
	}
	return dimension;
}


void turnBlock(int y, int x, int lev) {

	int smallN = pow(2, lev);
	int new_block[smallN][smallN];

	// copy
	for(int i=0; i<smallN; i++)
		for(int j=0; j<smallN; j++)
			new_block[i][j] = map[y+i][x+j];

	
	for(int i=0, m=0; i<smallN; i++, m++) {
		for(int j=smallN-1, n=0; j>=0; j--, n++) {
			map[y+m][x+n] = new_block[j][i];
		}
	}

}

bool checkNeighbor(int y, int x) {
	int ret = 0;

	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= bigN || nx < 0 || nx >= bigN) continue;
		if(map[ny][nx] > 0) ret++;
	}

	return ret >= 3;
}


void solve(int lev) {
	int smallN = pow(2, lev);

	// 	1. turn
	for(int i=0; i<bigN; i+=smallN) {
		for(int j=0; j<bigN; j+=smallN) {
			turnBlock(i,j,lev);
		}
	}
	
	vector <pair<int, int>> decrease;
	// 2. ice--;
	for(int i=0; i<bigN; i++)
		for(int j=0; j<bigN; j++) {
			if(!checkNeighbor(i, j))
				decrease.push_back(make_pair(i, j));
		}
	for(auto d: decrease) {
		if(map[d.first][d.second] > 0)
			map[d.first][d.second]--;
	}
	
}

void getAnswer() {
	int total = 0, dimension = 0;

	for(int i=0; i<bigN; i++)
		for(int j=0; j<bigN; j++) {
			if(map[i][j] <= 0) continue;
			total += map[i][j];
		}
	printf("%d\n", total);

	// get the biggest ice block
	for(int i=0; i<bigN; i++)
		for(int j=0; j<bigN; j++) {
			if(visit[i][j] == false && map[i][j] > 0)
				dimension = max(BFS(i, j),dimension);
		}

	printf("%d\n", dimension);
}

int main() {

	scanf("%d %d", &n, &q);

	bigN = pow(2, n);


	for(int i=0; i<bigN; i++)
		for(int j=0; j<bigN; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<q; i++) {
		int tmp;
		scanf("%d", &tmp);
		l.push_back(tmp);
	}


	for(int i=0; i<q; i++){
		solve(l[i]);
	}
	
	getAnswer();

	return 0;

}