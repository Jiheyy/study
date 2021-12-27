#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree {
	int y, x, age;
	Tree(int _y, int _x, int _age) : y(_y), x(_x), age(_age){};

};
const int dy[] = {-1 -1, -1, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, k;
int map[11][11];
int s2d2[11][11];
int x, y, z;
vector <Tree> tree[11][11];


bool compare(Tree a, Tree b) {

	if(a.age == b.age) {
		if(a.y == b.y)
			return a.x < b.x;
		return a.y < b.y;
	}

	return a.age < b.age;
}

vector <Tree> spring() {
	vector <Tree> dead;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			sort(tree[i][j].begin(), tree[i][j].end(), compare);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(tree[i][j].size() == 0) continue;

			int pos = 0;
			bool exist = true;
			for(int k=0; k<tree[i][j].size(); k++) {
				Tree t = tree[i][j][k];

				if(map[i][j] - t.age >= 0) {
					map[i][j] -= t.age;
					tree[i][j][k].age++;
				}
				else {
					if(exist) {
						exist = false;
						pos = k;
					}
					printf("%d %d %d\n", t.y, t.x, map[i][j]);
					dead.push_back(tree[i][j][k]);
					printf("%lu\n", dead.size());
				}
			}
			if(exist == false) {
				tree[i][j].erase(tree[i][j].begin() + pos, tree[i][j].end());
			}
		}
	}
	return dead;
}

void summer (vector <Tree> dead) {

	for(auto d: dead) {
		map[d.y][d.x] += (d.age / 2);
	}

}

void fall () {
	for(int i=0; i<=n; i++)
		for(int j=0; j<n; j++) {
			if(tree[i][j].size() == 0) continue;

			for(auto t: tree[i][j]) {
				if(t.age % 5 != 0) continue;

				for(int k=0; k<8; k++) {
					int ny = t.y + dy[k];
					int nx = t.x + dx[k];

					if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

					tree[ny][nx].push_back(Tree(ny, nx, 1));
				}
			}

		}
}

void winter() {

	for (int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			map[i][j] += s2d2[i][j];

}

void solve(int k) {

	while(k--) {
		vector <Tree> dead = spring();

		printf("trial: %d\n", int(dead.size()));
		
		summer(dead);

		fall();

		winter();

	}

}

int countTree() {
	int ret = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for (auto t: tree[i][j]) {
				//printf("%d %d %d\n", t.y, t.x, t.age);
				ret++;
			}
			

	return ret;
}

int main() {

	scanf("%d %d %d", &n, &m, &k);
	//k++;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			map[i][j] = 5;
	//memset(map, 5, sizeof(map));


	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			scanf("%d", &s2d2[i][j]);
		}

	for(int i=0; i<m; i++) {
		int y, x, z;
		scanf("%d %d %d", &x, &y, &z);
		x--; y--;
		tree[y][x].push_back(Tree(y, x, z));
	}


	solve(k);

	printf("%d\n", countTree());

	return 0;
}