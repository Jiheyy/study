#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[1000][1000];

int r, c, k;
int max_x, max_y;
int res;

bool compare(pair <int, int> a, pair<int, int> b) {
	if(a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

vector <int> counting(vector <int> v) {
	vector <pair <int, int>> nv;

	sort(v.begin(), v.end());

	int cnt = 1;
	for(int i=0; i<v.size()-1; i++) {
		if(v[i] == 0)
			continue;
		if(v[i] != v[i+1]) {
			nv.push_back(make_pair(v[i], cnt));
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	nv.push_back(make_pair(v[v.size()-1], cnt));
	sort(nv.begin(), nv.end(), compare);

	vector <int> ret;
	for(auto n: nv) {
		ret.push_back(n.first);
		ret.push_back(n.second);
	}
	return ret;
}

void R() {
	for(int y=0; y<max_y; y++) {
		vector <int> v;
		for(int x =0; x<max_x; x++) {
			v.push_back(map[y][x]);
		}
		v = counting(v);
		if(v.size() > max_x)
			max_x = v.size();
		
		for(int i=0; i<max_x; i++) {
			if(i >= v.size())
				map[y][i] = 0;
			else
				map[y][i] = v[i];
		}
		
	}

}

void C() {
	for(int x=0; x<max_x; x++) {
		vector <int> v;
		for(int y =0; y<max_y; y++) {
			v.push_back(map[y][x]);
		}
		v = counting(v);
		
		if(v.size() > max_y)
			max_y = v.size();
		for(int i=0; i<max_y; i++) {
			if(i >= v.size())
				map[i][x] = 0;
			else
				map[i][x] = v[i];
		}
	}
}

void solve() {
	if(max_y >= max_x)
		R();
	else
		C();
}


int main() {

	scanf("%d %d %d", &r, &c, &k);
	r--; c--;

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++)
			scanf("%d", &map[i][j]);
	}
	max_x = 3; max_y = 3;

	while(map[r][c] != k) {
		res++;
		solve();
		if(res > 100)
			break;
	}

	if(res > 100)
		printf("-1\n");
	else
		printf("%d\n", res);

}