#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
그 후, 십자가 두개의 크기를 각각 1씩 증가시켜 나가면서 넓이를 구했다.

그러나 이 방식은 완전탐색이 아니다.

왜냐하면 1번 십자가의 크기를 1 증가시킨 후 -> 1번과 2번 십자가가 겹치지 않는 한에서 2번 십자가의 크기를 1 증가한 뒤 넓이를 계산했기 때문이다. 완전탐색을 하려면 반대 순으로도 넓이를 각 경우에 대해 계산해야하며, 중간에도 계산을 한번 더 해야한다. 

즉,  아래와 같이 여러번의 계산이 필요한 것이다. 

1번 십자가 크기 1 증가 -> 넓이 계산 -> 2번 십자가 크기 1 증가 -> 넓이 계산
2번 십자가 크기 1 증가 -> 넓이 계산 -> 1번 십자가 크기 1 증가 -> 넓이 계산


첫번째 십자가의 가능한 크기가 0부터 max라고 했을 때,
모든 경우에 대해, 두번째 십자가의 가능한 크기를 모두 구해서 최대 넓이를 구하는 방식이다. 
*/

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int n, m;
int map[20][20];
bool visit[400];
pair<int, int> sharp[400];
int sharp_cnt;
int answer;

int bfs(pair <int, int> center[2]){

	int tmp[20][20];
	memset(tmp, 0, sizeof(tmp));
	int finish = 0;

	for(int i=0; i<2; i++) {
		int y = center[i].first;
		int x = center[i].second;

		tmp[y][x] = i+1;
	}

	while(finish < 2) {
		int length = 1;

		for(int i=0; i<2; i++) {

			if(center[i].first == -1) continue;

			int cy = center[i].first;
			int cx = center[i].second;

			bool ok = true;
			for(int dir=0; dir<4; dir++) {
				int ny = cy + (dy[dir] * length);
				int nx = cx + (dx[dir] * length);

				if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
					ok = false;
					break;
				}
				if(map[ny][nx] != 1 || tmp[ny][nx] != 0) {
					ok = false;
					break;
				}

			}
			if(ok == true) {
				for(int dir=0; dir<4; dir++) {
					int ny = cy + (dy[dir] * length);
					int nx = cx + (dx[dir] * length);
					tmp[ny][nx] = i+1;
				}
			}
			else {
				finish++;
				center[i].first = -1;
			}

		}
		length++;
	}
	int one = 0; int two = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			if(tmp[i][j] == 1)
				one++;
			if(tmp[i][j] == 2)
				two++;
		}
	
	return one * two;
}


int solve() {

	pair <int, int> center[2];
	
	int idx = 0;
	for(int i=0; i<sharp_cnt; i++) {
		// 십자가 중심
		if(visit[i] == true) {
			center[idx++] = sharp[i];
		}
	}
	
	return bfs(center);
}


void dfs(int idx, int cnt) {
	if(cnt == 2) {
		int ret = solve();
		answer = max(answer, ret);
		return;
	}

	for(int i=idx; i<sharp_cnt; i++) {
		if(visit[i]) continue;
		visit[i] = true;
		dfs(i, cnt+1);
		visit[i] = false;
	}

}
int main() {

	scanf("%d %d\n", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			char tmp;
			cin >> tmp;
			if(tmp == '#') {
				map[i][j] = 1;
				sharp[sharp_cnt++] = make_pair(i, j);
			}
			else if(tmp == '.')
				map[i][j] = 0;
		}

	dfs(0, 0);

	printf("%d\n", answer);

}