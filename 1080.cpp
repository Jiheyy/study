#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int n, m;
char map[51][51];
char answer[51][51];
int res;

void convert(int y, int x) {
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(y+i >= n || x+j >= m) {
				printf("-1\n");
				exit(0);
			}
			if(map[y+i][x+j] == '1')
				 map[y+i][x+j] = '0';
			else
				map[y+i][x+j] = '1';
		}
	}
	res++;
}

void solve() {

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(map[i][j] != answer[i][j]) {
				convert(i, j);
			}
		}
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) 
			if(map[i][j] != answer[i][j]) {
				printf("-1\n");
				exit(0);
			}
		
}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		cin >> map[i];

	for(int i=0; i<n; i++)
		cin >> answer[i];

	solve();

	printf("%d", res);
}