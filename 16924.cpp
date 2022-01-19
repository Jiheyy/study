#include <iostream>
#include <vector>
using namespace std;
char map[101][101];
int n, m;
bool visit[101][101];
struct A
{
int x, y, s;	
};

int check(int y, int x) {
	int i=0;
	while(true) {
		i++;
		if(map[y-i][x] == '*' && map[y+i][x] == '*' 
			&& map[y][x+i] == '*' && map[y][x-i] == '*') {
			visit[y-i][x] = true;
			visit[y+i][x] = true;
			visit[y][x+i] = true;
			visit[y][x-i] = true;
		}

		else {
			i--;
			break;
		}
	}

	if(i != 0) {
		for(int j=0; j<i; j++) {
			visit[y-j][x] = true;
			visit[y+j][x] = true;
			visit[y][x-j] = true;
			visit[y][x+j] = true;
		}
		return i; 
	}
	return 0;
}

int main() {

	vector <A> v;
	scanf("%d %d", &n, &m);

	for(int i=0; i<n; i++)
			cin >> map[i];

	for(int i=0; i<n; i++) {
		for(int j=1; j<m-1; j++){
			if(map[i][j-1] == '*' && map[i][j] == '*'&& map[i][j+1] == '*'){
				int sizes = check(i, j);
				if(sizes > 0){
					A a;
					a.y = i+1;
					a.x = j+1;
					a.s = sizes;
					v.push_back(a);
				}
			}
		}
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if((visit[i][j] == true && map[i][j] == '.') ||(visit[i][j] == false && map[i][j] == '*')) {
				printf("-1\n");
				exit(0);
			}
		}



	printf("%lu\n", v.size());
	for(int i=0; i<v.size(); i++)
		printf("%d %d %d\n", v[i].y, v[i].x, v[i].s);
	return 0;
}