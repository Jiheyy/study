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
vector <MOVE> mv;


int makeRange(int a) {
	if(a < 0)
		return n-1;
	if(a >= n)
		return 0;
	return a;
}


void solve() {

	vector <pair <int, int>> cloud;
	cloud.push_back(make_pair(n-1, 0));
	cloud.push_back(make_pair(n-1, 1));
	cloud.push_back(make_pair(n-2, 0));
	cloud.push_back(make_pair(n-2, 1));

	int idx = 0;
	while(idx < m) {
		vector <pair <int, int>> rain;
		for(int i=0; i<cloud.size(); i++) {

			int s = mv[idx].s;
			int d = mv[idx].d;
			int cy = cloud[i].first;
			int cx = cloud[i].second;

			while(s--) {
				int ny = cy + dy[d];
				int nx = cx + dx[d];

				cy = makeRange(ny);
				cx = makeRange(nx);
			}
			cloud[i].first = cy;
			cloud[i].second = cx;
		}

		bool visit[50][50] = {false,};

		for(int i=0; i<cloud.size(); i++) {
			int y = cloud[i].first;
			int x = cloud[i].second;
			map[y][x]++;
			visit[y][x] = true;
			rain.push_back(make_pair(y, x));
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
					cloud.push_back(make_pair(i, j));
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