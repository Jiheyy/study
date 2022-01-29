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

시간초과

첫번째 십자가의 가능한 크기가 0부터 max라고 했을 때,
모든 경우에 대해, 두번째 십자가의 가능한 크기를 모두 구해서 최대 넓이를 구하는 방식이다. 
*/

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int n, m;
char map[20][20];
bool visit[400];
pair<int, int> sharp[400];
int sharp_cnt;
int answer;
int choice[5];
char cmap[20][20];

void copy_map() {

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cmap[i][j] = map[i][j];
}

// 길이를 리턴
int get_max(int y, int x) {

	int length = 1;

	while(true) {

		if(y-length < 0 || y+length >=n || x-length < 0 || x+ length >= m)
			break;

		if(cmap[y-length][x] == '#' && cmap[y+length][x] == '#' &&
		 cmap[y][x-length] == '#' && cmap[y][x+length] == '#' ) {
			length++;
		}

		else
			break;
	}
	length--;

	return length;
}

void draw(int y, int x, int length) {

	for(int i=0; i<=length; i++) {
		cmap[y-i][x] = '.';
		cmap[y+i][x] = '.';
		cmap[y][x-i] = '.';
		cmap[y][x+i] = '.';
	}

}

void solve() {

	// copy map 
	copy_map();

	int fy = sharp[choice[0]].first;
	int fx = sharp[choice[0]].second;
	int sy = sharp[choice[1]].first;
	int sx = sharp[choice[1]].second;


	int first_max = get_max(fy, fx); // 최대 길이를 구함

	for(int i=0; i<=first_max; i++) {
		// draw in copy
		draw(fy, fx, i); // 한칸씩 넓혀보기
		int first_size = 1+(4*i);

		int second_max = get_max(sy, sx); // 두번쨰의 가능한 최대 길이
		int second_size = 1 + (4*second_max); // 넓이

		answer = max(first_size * second_size, answer);
	}

}


void dfs(int idx, int cnt) {
	if(cnt == 2) {
		solve();
		return;
	}

	for(int i=idx; i<sharp_cnt; i++) {
		if(visit[i]) continue;
		visit[i] = true;
		choice[cnt] = i;
		dfs(i, cnt+1);
		visit[i] = false;
	}

}
int main() {

	scanf("%d %d\n", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) {
			cin >> map[i][j];
			if(map[i][j] == '#') {
				sharp[sharp_cnt++] = make_pair(i, j);
			}
		}

	dfs(0, 0);

	printf("%d\n", answer);

}