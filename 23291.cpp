#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, k;
vector <vector<int>> board;

bool if_end() {
	int max_fishes = *max_element(board[0].begin(), board[0].end());
	int min_fishes = *min_element(board[0].begin(), board[0].end());

	return ((max_fishes-min_fishes) <= k);

}

void move_fishes() {
	vector <vector<int>> new_board = board;

	for(int y = 0; y<n; y++) {
		for(int x = 0; x<n; x++) {
			if(board[y][x] == -1) continue;
			for(int dir = 0; dir<4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if(ny <0 || nx <0 || ny >= n || nx >= n|| board[ny][nx] == -1)
					continue;

				new_board[y][x] += (int) (board[ny][nx] - board[y][x]) / 5;
			}
		}
	}
	// make it back to line
	vector <int> flat_board;
	for(int x = 0; x<n; x++)
		for(int y = 0; y<n; y++) {
			if(new_board[y][x] == -1) continue;
			else
				flat_board.push_back(new_board[y][x]);
		}
	// init board
	board = vector<vector<int>>(n, vector<int> (n, -1));
	board[0] = flat_board; // 대입 
}


void move() {
	int ly = 1, lx = 1; // 움직일 어항의 세로길이, 가로길이
	int sx = 0;// 움직일 어항의 시작좌표
	// put fish
	int min_fishes = *min_element(board[0].begin(), board[0].end());
	for(int i=0; i<n; i++){
		if(board[0][i] == min_fishes)
			board[0][i]++;
	}
	//
	while(sx + ly + lx <= n) {
		
		for(int y = 0; y<ly; y++){
			for(int x = 0; x<lx; x++){
				int ny = lx - x;
				int nx = sx + lx + y;
				board[ny][nx] = board[y][x+sx];
				board[y][x+sx] = -1;
			}
		}
		sx += lx;
		if(ly == lx) ly++;
		else lx++;
	}

	// move fishes
	move_fishes();

	// 2번이동
	sx = 0;
	ly = 1;
	lx = n/2;

	for(int i=0; i<2; i++) {
		for(int y = 0; y<ly; y++) {
			for(int x = 0; x<lx; x++) {
				int ny = 2 * ly - y -1;
				int nx = 2 * lx + sx - x -1;
				board[ny][nx] = board[y][x+sx];
				board[y][x+sx] = -1;
			}
		}
		sx += lx;
		lx /= 2;
		ly *= 2;
	}

	move_fishes();


}

void solve() {
	int count = 0;
	while(!if_end()) {
		count++;
		move();
	}
	printf("%d\n", count);
}



int main() {

	scanf("%d %d", &n, &k);

	board = vector <vector<int>> (n, vector<int> (n, -1));

	for(int i=0; i<n; i++)
		scanf("%d", &board[0][i]);

	solve();

}