#include <iostream>
#include <vector>
using namespace std;

int n, m, t;

vector <vector <int>> board;

void turn(int no, int dir) {
	if(dir == 0) { // clockwise
		int tmp = board[no][m-1];
		for(int i=m-2; i>=0; i--){
			board[no][i+1] = board[no][i];
		}
		board[no][0] = tmp;
	}

	else { // anti-clockwise
		int tmp = board[no][0];
		for(int i=0; i<m-1; i++)
			board[no][i] = board[no][i+1];
		board[no][m-1] = tmp;
	}

	//for(int i=0; i<n; i++)
	//	printf("%d ", board[no][i]);
}

void check() {
	vector <pair <int, int>> same;
	double avg = 0;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(board[i][j] < 0) continue;
			avg += board[i][j];
			cnt++;

			if(j==0) {
				if(board[i][0] == board[i][1]) {
					same.push_back(make_pair(i, 0));
					same.push_back(make_pair(i, 1));
				}
				if(board[i][0] == board[i][m-1]) {
					same.push_back(make_pair(i, 0));
					same.push_back(make_pair(i, m-1));
				}
			}
			else if(j==m-1) {
				if(board[i][j] == board[i][j-1]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i, j-1));
				}
				if(board[i][j] == board[i][0]) {
					same.push_back(make_pair(i, 0));
					same.push_back(make_pair(i, j));
				}
			}
			else {
				if(board[i][j] == board[i][j-1]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i, j-1));
				}
				if(board[i][j] == board[i][j+1]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i, j+1));
				}
			}

			if(i == 0) {
				if(board[i][j] == board[i+1][j]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i+1, j));
				}
			}
			else if (i== n-1) {
				if(board[i][j] == board[i-1][j]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i-1, j));
				}
			}
			else {
				if(board[i][j] == board[i-1][j]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i-1, j));
				}
				if(board[i][j] == board[i+1][j]) {
					same.push_back(make_pair(i, j));
					same.push_back(make_pair(i+1, j));
				}

			}

		}
	}

	//printf("---------\n");
	if(same.size() == 0) {
		avg = avg/cnt;

		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) {
				if(board[i][j] < 0) continue;
				if(board[i][j] > avg) {
					//printf("small\n");
					board[i][j] -= 1;
				}
				else if(board[i][j] < avg) {
					board[i][j] += 1;
				}
			}
	}
	else {

		for(auto s: same) {
			if(board[s.first][s.second] == -1) continue;		
			//printf("delete : %d %d %d\n", s.first, s.second, board[s.first][s.second]);
			board[s.first][s.second] = -1;
			//printf("delete : %d %d\n", s.first, s.second);
		}
	}
}


void solve(int x, int d, int k) {

	for(int i=1; i<=n; i++) {
		int times = k;
		if(i % x != 0) continue;
		while(times--) {
			turn(i-1, d);
		}
	}
	check();
}

int count() {
	int ret = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			if(board[i][j] < 0) continue;
			ret += board[i][j];
		}

	return ret;

}

int main() {
	
	scanf("%d %d %d", &n, &m, &t);

	for(int i=0; i<n; i++){
		vector <int> tmp(m);
		for(int j=0; j<m; j++) {
			scanf("%d",&tmp[j]);
		}
		board.push_back(tmp);
	}

	int x, d, k;
	for(int i=0; i<t; i++) {
		scanf("%d %d %d", &x, &d, &k);
		solve(x, d, k);
	}

	printf("%d\n", count());
}