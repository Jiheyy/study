#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS
int n, m, h;
int map[32][12];
int res;

bool draw() {
	
	for(int x=1; x<=n; x++) {
		int cur_x = x;
		for(int y=1; y<=h; y++) {
			if(map[y][cur_x] == 1) cur_x++;
			
			else if(map[y][cur_x-1] == 1) cur_x--;
		}
		if(cur_x != x)
			return false;
	}

	return true;
}


void DFS(int y, int x, int dep) {
	if(res <= dep) return;

	if(draw()) {
		res = dep;
		return;
	}
    if(dep == 3) return;

	for(int cy=y; cy<=h; cy++) {
		for(int cx =x; cx<=n; cx++) {
			if(map[cy][cx] != 0 || map[cy][cx-1] != 0 || map[cy][cx+1] != 0) continue;
			map[cy][cx] = 1;
			DFS(cy, cx, dep+1);
			map[cy][cx] = 0;
			
		}
		x = 1;
	}
}



int main() {
	scanf("%d %d %d", &n, &m, &h);

	for(int i=0; i<m; i++) {
		int a, b;
		scanf("%d %d",&a, &b);
		map[a][b] = 1;
	}
	
	res = 4;
	DFS(1, 1, 0);


    if(res == 4)
        printf("-1\n");
    else
	   printf("%d\n", res);

	return 0;

}