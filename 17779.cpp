#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
int map[21][21];
int visit[21][21];

void divide(int x, int y, int d1, int d2) {
	bool answer = false;

	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++) 
			visit[i][j] = 0;

	for(int c=0; c<= d1; c++)
		visit[y-c][x+c] = 5;

	for(int i=0; i<= d2; i++)
		visit[y+i][x+i] = 5;

	for(int i=0; i<=d2; i++)
		visit[y-d1+i][x+d1+i] = 5;

	for(int i=0; i<=d1; i++)
		visit[y+d2-i][x+d2+i] = 5;

	for(int i=1; i<=n; i++) { // x
		int first = -1; int second = -1; 
		for(int j=1; j<=n; j++) {// y
			if(visit[j][i] == 5 && first == -1)
				first = j;
			else if(first != -1 && visit[j][i] == 5)
				second = j;
		}
		if(first != -1 && second != -1) {
			for(int n=first; n<=second; n++)
				visit[n][i] = 5;
		}
	}


	for(int c=1; c<=y; c++)
		for(int r=1; r<x+d1; r++) {
			if(visit[c][r] == 5) continue;
			visit[c][r] = 1;
		}

	for (int c=y+1; c<=n; c++)
		for(int r = 1; r<= x+d2; r++){
			if(visit[c][r] == 5) continue;
			visit[c][r] = 3;
		}

	for(int c=1; c<y-d1+d2; c++)
		for(int r=x+d1; r<=n; r++){
			if(visit[c][r] == 5) continue;
			visit[c][r] = 2;
		}

	for(int c=y-d1+d2; c<=n; c++) 
		for(int r=x+d2+1; r<= n; r++) {
			if(visit[c][r] == 5) continue;
			visit[c][r] = 4;
		}

	if(answer) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
	}


}

void count() {
	


	vector <int> v(5);
	for(int i=0; i<5; i++)
		v[i] = 0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			v[visit[i][j]-1] += map[i][j];
		}

	sort(v.begin(), v.end());

	if(res > v[4] - v[0])
		res = v[4]-v[0];
	if(res > 19)
		return;

}

void solve() {
	for(int x=1; x <=n; x++) {
		for(int y=1; y<=n; y++) {
			for(int d1=1; d1<=n; d1++) {
				for(int d2 = 1; d2 <=n; d2++) {
					if((x < x+d1+d2 && x+d1+d2 <= n) && 1 <= y-d1 && y-d1 < y && y < y+d2 && y+d2 <= n) {
						divide(x, y, d1, d2);
						count();
					}
				}
			}
		}
	}

	
}

int main()
{
	res = 987654321;
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d", &map[j][i]);

	solve();


	printf("%d\n", res);
	return 0;
}