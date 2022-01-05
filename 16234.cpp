#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

struct Union {
	vector <pair <int, int>> v;

	int size() {
		return v.size();
	}
};

vector <Union> uni;

int n, l, r;
int a[51][51];
int days;
bool visit[51][51];

bool compare(int i, int j) {
	int n1 = max(i, j);
	int n2 = min(i, j);
	return ((n1 - n2 >= l) && (n1-n2 <= r));
}

vector<pair<int, int>> BFS(int i, int j) {

	vector <pair <int, int>> v;
	queue <pair <int, int>> q;

	visit[i][j] = true;
	q.push(make_pair(i, j));


	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop(); 
		v.push_back(make_pair(y, x));

		for(int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

			if(visit[ny][nx] == false && compare(a[y][x], a[ny][nx])) {
				visit[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
	//printf("return %lu\n");

	return v;

}



int main() {

	scanf("%d %d %d", &n, &l, &r);

	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	days = 0;

	while(true) {
		days++;
		uni.clear();
		memset(visit, false, sizeof(visit));

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(visit[i][j] == false) {
					Union tmp;
					tmp.v = BFS(i, j);
					if(tmp.v.size() < 2)
						continue;
					uni.push_back(tmp);
				}

		if(uni.size() < 1) {
			days--;
			break;
		}


		for(int j=0; j<int(uni.size()); j++) {
			int total = 0;
			vector <pair <int , int>> u = uni[j].v;
			for(int i=0; i<int(u.size()); i++) {
				int y = u[i].first;
				int x= u[i].second;
				total += a[y][x];
			}
			for(int i=0; i<int(u.size()); i++) {
				int y = u[i].first;
				int x = u[i].second;
				a[y][x] = total / int(u.size());
			}
		}
		
	}

	printf("%d", days);



}