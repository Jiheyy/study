#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Camera {
	int y, x, dir, no;
};
vector <Camera> cam;
int n, m;
int res = 987654321;
int map[10][10];

vector<int> v;

// clock wise
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

bool select[10];

bool checkBound(int y, int x){
	if (y < 0 || y >= n || x < 0 || x >= m)
		return false;

	return true;
} 


void setCam(vector <int> v) {

	bool visit[10][10] = {false,};

	for(int i=0; i<v.size(); i++) {
		Camera c = cam[i];
		int dir = v[i];

		vector <int> sight;

		if(c.no == 1) {
			int right_d = (dir+1) % 4;
			sight.push_back(right_d);
		}
		else if(c.no == 2) {
			int left_d = (dir + 3) %4;
			int right_d = (dir +1) %4;
			sight.push_back(left_d);
			sight.push_back(right_d);	
		}
		else if(c.no == 3) {
			int up_d = dir % 4;
			int right_d = (dir+1) % 4;
			sight.push_back(up_d);
			sight.push_back(right_d);
		}
		else if(c.no == 4) {
			int up_d = dir % 4;
			int left_d = (dir + 3) %4;
			int right_d = (dir +1) %4;
			sight.push_back(up_d);
			sight.push_back(left_d);
			sight.push_back(right_d);	
		}
		else if (c.no == 5) {
			sight.push_back(0);
			sight.push_back(1);
			sight.push_back(2);
			sight.push_back(3);
		}

		for(int s=0; s<sight.size(); s++) {
			int ny = c.y;
			int nx = c.x;
			visit[ny][nx] = true;

			while(true) {
				int ny = ny + dy[sight[s]];
				int nx = nx + dx[sight[s]];

				if(checkBound(ny, nx) == false) break;

				if(map[ny][nx] == 6) {
					visit[ny][nx] = true;
					break;
				}
				if(map[ny][nx] > 0 && map[ny][nx] <= 5) {
					visit[ny][nx] = true;
					continue;
				}
				else if(map[ny][nx] == 0){
					visit[ny][nx] = true;
				}
			}
		}
	}

	

	// count invisible spot
	int invisible = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) 
			if(visit[i][j] == false)
				invisible++;


	res = min(res, invisible);

}

// 중복 순열 
// 4 개로 카메라갯수만큼 길이의 순열을 구해야함
void DFS(int cnt) {

	if(cnt == cam.size()) {
		setCam(v);
		return;
	}

	for(int i=0; i<4; i++) {
		v.push_back(i);
		DFS(cnt+1);
		v.pop_back();
	}
}


int main() {

	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0) {
				Camera tmp;
				tmp.y = i; tmp.x = j;
				tmp.no = map[i][j];
			}
		}

	DFS(0);

	printf("%d\n", res);

}