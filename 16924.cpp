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
	int i=1;
	while(true) {
		if(map[y-i][x] == '*' && map[y+i][x] == '*' 
			&& map[y][x+i] == '*' && map[y][x-i] == '*') {
			visit[y-i][x] = true;
			visit[y+i][x] = true;
			visit[y][x+i] = true;
			visit[y][x-i] = true;
			
			i++;
		}

		else {
			break;
		}
	}
	i--;
	if(i > 0)
		visit[y][x] = true;
	/*
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(visit[i][j] == true)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
	*/

	return i*4+1;
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
				if(sizes >= 5){
					A a;
					a.y = i+1;
					a.x = j+1;
					a.s = sizes;
					v.push_back(a);
				}
			}
		}
	}

	int cnt = 0;
	int star = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(visit[i][j]== true)
				cnt++;
			if(map[i][j] == '*')
				star++;
		}


	if(cnt == star && cnt != 0) {
		printf("%lu\n", v.size());

	}
	else 
		printf("-1\n");
	return 0;
}