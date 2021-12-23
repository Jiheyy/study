#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int res = 0;
int arr[503][503];

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

bool visit[503][503] = {false};

// DFS
int DFS(int y, int x, int cnt) {

	if(cnt == 4) 
		return arr[y][x];
	
	int sum = 0;

	// 2. check each v ele.
	for(int i=0; i<4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny < 0 || ny >= n || nx < 0 || nx >=m) continue;
		if(visit[ny][nx]) continue;
		visit[ny][nx] = true;
		sum = max(sum, arr[y][x] + DFS(ny, nx, cnt+1));
		visit[ny][nx] = false;
	}
	
	return sum;
	
}

int middleFinger(int y, int x) {

	int result = 0;

	// ㅗ
	if(x < m-1 && x >=1 && y >= 1) {
		result = max(result, arr[y][x-1] + arr[y][x] + arr[y][x+1] + arr[y-1][x]);
	}
	
	// ㅏ
	if(x< m-1 && y < n-1 && y >= 1) {
		result = max(result, + arr[y-1][x] + arr[y][x] + arr[y+1][x] + arr[y][x+1]);
	}

	// ㅜ
	if(y >= 0 && x < m-1 && y < n-1) {
		result = max(result, arr[y][x] + arr[y][x-1] + arr[y][x+1] + arr[y+1][x]);
	}

	// ㅓ
	if(x >=1 && y >= 1 && y < n-1) {
		result = max(result,arr[y][x] + arr[y-1][x] + arr[y][x-1] + arr[y+1][x]);
	}

	return result;
}



int main() {
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d" ,&arr[i][j]);
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			visit[i][j] = true;
			res = max(res, DFS(i, j, 1));
			res = max(res, middleFinger(i, j));
			visit[i][j] = false;
		}

	printf("%d\n", res);
	return 0;
}