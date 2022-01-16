#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m, res, empty_place;
int map[51][51];

vector <pair<int, int>> v;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};


int bfs(vector <pair<int, int>> v) {

	queue <pair<int, int>> q;
	int visit[51][51];
	memset(visit, -1, sizeof(visit));

	for(int i=0; i<v.size(); i++) {
		q.push(v[i]);
		visit[v[i].first][v[i].second] = 0;
	}

	int infect = 0;
	int total_time = 0;

	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n || visit[ny][nx] != -1)
				continue;

			if(map[ny][nx] == 1) // 벽은 스킵
				continue;

			visit[ny][nx] = visit[y][x] +1; // 방문은 했고

			if(map[ny][nx] == 0) {
				infect++;
				total_time = visit[ny][nx]; // 빈칸일때만 시간을 갱신해준다.
			}
				
			q.push(make_pair(ny, nx));
			
		}

	}

	if(infect != empty_place)
		return 987654321;

	return total_time;
}

int Arr[11] = {0,1,2,3,4,5,6,7,8,9,10};
bool Select[11];

void dfs(int idx, int cnt, int target_num) {
	if (cnt == target_num)
    {	
    	vector <pair <int, int>> tmp;
        for (int i=0; i<v.size(); i++) 
            if (Select[i]) {
            	tmp.push_back(v[Arr[i]]);

            }
        int depth = bfs(tmp);
        if(depth < res)
        	res = depth;
        
        return;
    }
 
    for (int i = idx; i < v.size(); i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;

        dfs(i, cnt + 1, target_num);
        Select[i] = false;
    }

}


void solve() {
	// v 조합
	dfs(0, 0, m);
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2)
				v.push_back(make_pair(i, j));
			if(map[i][j] == 0)
				empty_place++;
		}
	res = 987654321;
	solve();

	if(res == 987654321)
		printf("-1\n");
	else
		printf("%d\n", res);


}
