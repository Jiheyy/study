#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m, res;
int map[51][51];

struct MOVE{
	int s;
	int d;
};

struct Cloud {
	int y, x;
};

vector <MOVE> mv;


int makeRange(int a) {
	if(a < 0)
		return n-1;
	if(a >= n)
		return 0;
	return a;
}


void solve() {

	vector <Cloud> cloud;
	Cloud c1, c2, c3, c4;
	c1.y = n-1; c1.x = 0; 
	c2.y = n-1; c2.x = 1;
	c3.y = n-2; c3.x = 0; 
	c4.y = n-2; c4.x = 1;
	cloud.push_back(c1);
	cloud.push_back(c2);
	cloud.push_back(c3);
	cloud.push_back(c4);

	int idx = 0;
	while(idx < m) {
		vector <pair <int, int>> rain;
		for(int i=0; i<cloud.size(); i++) {

			int s = mv[idx].s;
			int cy = cloud[i].y;
			int cx = cloud[i].x;

			while(s--) {
				int ny = cy + dy[mv[idx].d];
				int nx = cx + dx[mv[idx].d];

				cy = makeRange(ny);
				cx = makeRange(nx);
			}

			cloud[i].x = cx;
			cloud[i].y = cy;
		}

		bool visit[50][50] = {false,};

		for(int i=0; i<cloud.size(); i++) {
			int y = cloud[i].y;
			int x = cloud[i].x;
			//if(visit[y][x] == false) {
			map[y][x]++;
			visit[y][x] = true;
			rain.push_back(make_pair(y, x));
			//}
		}

		cloud.clear();

		int d_y[4] = {-1, -1, 1, 1};
		int d_x[4] = {-1, 1, 1, -1};

		for(int i=0; i<rain.size(); i++) {
			int cnt = 0;
			int x = rain[i].second;
			int y = rain[i].first;

			for(int j=0; j<4; j++) {
				int ny = y + d_y[j];
				int nx = x + d_x[j];

				if(ny < 0 || ny >= n || nx < 0 || nx >= n || map[ny][nx] == 0) continue;
				cnt++;

			}
			map[y][x] += cnt;
		}

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				if(map[i][j] >= 2 && visit[i][j] == false) {
					Cloud c1;
					c1.y = i; c1.x = j; 
					cloud.push_back(c1);
					map[i][j]-=2;
				}
			}

		idx++;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {	
			if(map[i][j] > 0)
				res += map[i][j];
		}
	}
}


int main() {
	scanf("%d %d",&n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<m; i++) {
		MOVE tmp;
		scanf("%d %d", &tmp.d, &tmp.s);
		tmp.d--;
		mv.push_back(tmp);
	}


	solve();
	printf("%d\n", res);

	return 0;
}