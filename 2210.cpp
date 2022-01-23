#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int arr[5][5];
bool check[1000000];
int answer;

void dfs(int y, int x, int cnt, int num, int target) {
	if(cnt == target) {
		if(check[num] == false) {
			check[num] = true;
			answer++;
		}
		return;
	}

	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		int new_num = num + arr[ny][nx] * pow(10, 5-cnt);
		dfs(ny, nx, cnt+1, new_num, target);
	}
}

int main(){

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			scanf("%d", &arr[i][j]);

	for(int y=0; y<5; y++)
		for(int x=0; x<5; x++) {
			int num = arr[y][x] * pow(10, 5);
			dfs(y, x, 1, num, 6);
		}


	printf("%d\n", answer);


	return 0;
}