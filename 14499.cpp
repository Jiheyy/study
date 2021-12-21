#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int x, y;
int k;
int arr[21][21];
int Dice[7];

vector <int> cmd;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, -1, 1};


void roll_dice(int d) {

	int d1, d2, d3, d4, d5, d6;
    d1 = Dice[1], d2 = Dice[2], d3 = Dice[3];
    d4 = Dice[4], d5 = Dice[5], d6 = Dice[6];
 
    if (d == 0)
    {
        Dice[1] = d4;
        Dice[4] = d6;
        Dice[6] = d3;
        Dice[3] = d1;
    }
    else if (d == 1)
    {
        Dice[4] = d1;
        Dice[6] = d4;
        Dice[3] = d6;
        Dice[1] = d3;
    }
    else if (d == 2)
    {
        Dice[1] = d5;
        Dice[2] = d1;
        Dice[6] = d2;
        Dice[5] = d6;
    }
    else if (d == 3)
    {
        Dice[5] = d1;
        Dice[1] = d2;
        Dice[2] = d6;
        Dice[6] = d5;
    }
}

void solve() {

 	for(int i=0; i<cmd.size(); i++) {
		int ny = y + dy[cmd.at(i)];
		int nx = x + dx[cmd.at(i)];
		int d = cmd.at(i);

		if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

		roll_dice(d);
		if(arr[nx][ny] == 0)
			arr[nx][ny] = Dice[6];
		else {
			Dice[6] = arr[nx][ny];
			arr[nx][ny] = 0;
		}

		printf("%d\n", Dice[1]);
		x = nx;
		y = ny;
	}

}

int main() {

	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &arr[i][j]);
		} 
	}


	for(int i=0; i<k; i++) {
		int tmp;
		scanf("%d", &tmp);
		tmp--;
		cmd.push_back(tmp);
	}

	solve();

	return 0;

}