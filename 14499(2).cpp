#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int Dice[7];
int n, m, k;
int x, y;
int map[21][21];
vector <int> cmd;

void roll(int c) {
	int d0 = Dice[0];
	int d1 = Dice[1];
	int d2 = Dice[2];
	int d3 = Dice[3];
	int d4 = Dice[4];
	int d5 = Dice[5];

	if(c == 0) {
		Dice[5] = d1;
		Dice[4] = d3;
		Dice[1] = d4;
		Dice[3] = d5;
	}
	else if (c == 1) {

	}
}

void solve() {

	for(int i=0; i<cmd.size(); i++) {
		int command = cmd[i];
		int dir = cmd[i];
		int ny = y + dy[dir];
		int nx = x + dx[dir];


		//check board

		// roll dice
	}

}

int main() {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &map[i][j]);

	for(int i=0; i<k; i++) {
		int tmp;
		scanf("%d", &tmp);
		tmp--;
		cmd.push_back(tmp);
	}

	solve();


	return 0;
}