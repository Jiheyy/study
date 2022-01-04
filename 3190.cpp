#include  <iostream>
#include <vector>
#include <deque>

using namespace std;


int dx[4] = { -1, 0 , 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
/*
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
*/
/*
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
*/
int n, k, l, res;
int map[101][101];

struct Snake {
	vector <pair <int, int>> v;
	int dir, size;
};

Snake snake;

vector <pair <int, char>> turn;

bool checkBlock(int y, int x) {
	if(y >= n || x >= n || y < 0 || x < 0)
		return false;

	return true;
}



bool solve() {
	int idx = 0;

	while(true) {
		res++;
		
		pair <int, int> head;

		head = snake.v.front();

		snake.size++;
		int ny = head.first + dy[snake.dir];
		int nx = head.second + dx[snake.dir];

		// game end
		if(!checkBlock(ny, nx) || map[ny][nx] == 2) {
			printf("END\n");
			return false;
		}

		printf("%d:: %d %d %d\n", res,ny, nx, snake.dir);

		
		if (map[ny][nx] == 0) {
			map[ny][nx] = 2;
			map[snake.v.back().first][snake.v.back().second] = 0;
			snake.v.pop_back();
			snake.v.insert(snake.v.begin(), make_pair(ny, nx));
			//snake.size--;
		}
		// apple exits
		else if(map[ny][nx] == 1) {
			map[ny][nx] = 2;
			snake.v.insert(snake.v.begin(), make_pair(ny, nx));
		}
		
		// 회전
		if(idx < turn.size()) {
			if(res == turn[idx].first) {

				if(turn[idx].second == 'L') {
					snake.dir = (snake.dir + 3) % 4;
					//snake.dir = Turn_Direction(snake.dir, 'L');
				}
				else if(turn[idx].second == 'D') {
					snake.dir = (snake.dir + 1) % 4;
					//snake.dir = Turn_Direction(snake.dir, 'D');
				}
				printf("Turn %d\n", snake.dir);
				idx++;
			}
		}
	}

	return true;
}

int main() {

	snake.v.push_back(make_pair(0, 0));
	snake.size = 1;
	snake.dir = 1; // right;
	map[0][0] = 2; // snake


	scanf("%d", &n);

	scanf("%d", &k);

	for(int i=0; i<k; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		y--; x--;
		map[y][x] = 1; // apple
	}

	scanf("%d", &l);

	while(l--) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		turn.push_back(make_pair(x, c));
		//if (!solve(x, c))
		//	break;
		//printf(">> %d\n", res);
	}

	solve();

	printf("%d\n", res);


	return 0;
}