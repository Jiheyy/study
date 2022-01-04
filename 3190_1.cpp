#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k, l, res;
int map[101][101];

int x, y, dir;

vector <pair <int, char>> turn;
deque <pair <int, int>> snake;


void solve() {
	int idx = 0;

	while(true) {
		res++;

		int ny = snake.front().first + dy[dir];
		int nx = snake.front().second + dx[dir];

		if(ny < 0 || ny >= n || nx >= n || nx < 0 || map[ny][nx] == 2) break;

		else if(map[ny][nx] == 0) {
			snake.push_front(make_pair(ny, nx));
			map[ny][nx] = 2;
			map[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		else if(map[ny][nx] == 1) {
			snake.push_front(make_pair(ny, nx));
			map[ny][nx] = 2;
		}

		if(idx < turn.size()) {
			if(turn[idx].first == res) {
				if(turn[idx].second == 'D')
					dir = (dir + 1) % 4;
				if(turn[idx].second == 'L')
					dir = (dir + 3) % 4;
				idx++;
			}
		}

	}
}

int main() {

	x = 0; y = 0; dir = 1;
	map[y][x] = 2;
	snake.push_front(make_pair(y, x));

	scanf("%d", &n);
	scanf("%d", &k);

	for(int i=0; i<k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		map[a][b] = 1;
	}

	scanf("%d", &l);
	while(l--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		turn.push_back(make_pair(x, c));
	}

	solve();

	printf("%d\n", res);

	return 0;
}