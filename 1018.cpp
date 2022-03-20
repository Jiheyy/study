#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int y, x;
string map[59];
string answer[2][10];
int result = 987654321;

void check_board(int cy, int cx) {
	int case_1 = 0;
	int case_2 = 0;

	for(int i=0; i<8; i++) {
		for(int j=0; j<8; j++) {
			if(answer[0][i][j] != map[cy+i][cx+j]) 
				case_1++;
			
			if(answer[1][i][j] != map[cy+i][cx+j])
				case_2++;
		}
	}
	result = min(result, case_1);
	result = min(result, case_2);
} 

int main() {
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++) {
		cin >> map[i];
	}

	string a = "BWBWBWBW";
	string b = "WBWBWBWB"; 
	for(int i=0; i<8; i++){
		answer[0][i] = a;
		answer[1][i] = b;
		string tmp = a;
		a = b;
		b = tmp;
	}


	for(int i=0; i<=n-8; i++)
		for(int j=0; j<=m-8; j++)
				check_board(i, j);

	cout << result << endl;
}