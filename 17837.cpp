#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

struct MAL {
	int y, x, floor, dir;
};

vector <MAL> mal;

int n,k, answer;
int map[13][13];

vector <int> ele[13][13];

void solve() {

	while(answer < 1000) {
		answer++;
		for(int i=0; i<k; i++) {
			int y = mal[i].y;
			int x = mal[i].x;
			int dir = mal[i].dir;
			int floor = mal[i].floor;

			int ny = y + dy[dir];
			int nx = x + dx[dir];
			//blue
			if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 2) {
				if(dir == 0 || dir == 2)
					dir++;
				else
					dir--;

				mal[i].dir = dir;

				ny = y + dy[dir];
				nx = x + dx[dir];

				if(ny < 1 || ny > n || nx < 1 || nx > n || map[ny][nx] == 2) {// do not move
					continue;
				}
			}

			vector <int> target;
			target.clear();

			for(int i=ele[y][x].size()-1; i>=floor; i--) {
				int mal_idx = ele[y][x][i];
				target.push_back(mal_idx);
				ele[y][x].pop_back();
			}
			// red
			if(map[ny][nx] == 1) {
				int height = ele[ny][nx].size()-1;
				for(auto t: target) {
					ele[ny][nx].push_back(t);
					mal[t].y = ny;
					mal[t].x = nx;
					mal[t].floor = ++height;
				}
			}
			// white
			else if(map[ny][nx] == 0) {
				int height = ele[ny][nx].size()-1;
				for(int j=target.size()-1; j>=0; j--) {
					ele[ny][nx].push_back(target[j]);
					mal[target[j]].y = ny;
					mal[target[j]].x = nx;
					mal[target[j]].floor = ++height;
				}
			}

			if (ele[ny][nx].size() >= 4) {
				return;
			}
			
		}
	}
}




int main() {

	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			scanf("%d", &map[i][j]);
		}

	for(int i=0; i<k; i++) {
		MAL tmp;
		scanf("%d %d %d", &tmp.y, &tmp.x, &tmp.dir);
		tmp.dir--; tmp.floor = 0;
		mal.push_back(tmp);

		ele[tmp.y][tmp.x].push_back(i); // 말의 번호를 push_back
	}

	solve();

	if(answer >= 1000)
		printf("-1\n");
	else
		printf("%d\n", answer);
}

