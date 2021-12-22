#include <iostream>
#include <vector>

using namespace std;

struct Fire {
	int y, x, m, d, s;
};

vector <Fire> fire;
int n, m, k; // x, y, commamd
int res;
vector <Fire> map[51][51];

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void count() {
	for(int i=0; i<fire.size(); i++) {
		res += fire[i].m;
	}
}

void solve() {

	while(k--) {

		// 1. move
		for(int i=0; i<fire.size(); i++) {

			int ny = (fire[i].y + (dy[fire[i].d] * fire[i].s)) % n;
			int nx = (fire[i].x + (dx[fire[i].d] * fire[i].s)) % n;
			
			if(nx < 0)
				nx += n;
			if(ny < 0)
				ny += n;

			fire[i].x = nx;
			fire[i].y = ny;
		}

		// 2. clear map
		for(int i=0; i<n; i++) 
			for(int j=0; j<n; j++)
				map[i][j].clear();


		// 3. put new pos into map
		for(int i=0; i<fire.size(); i++) {
			map[fire[i].y][fire[i].x].push_back(fire[i]);
		}

		fire.clear();
	
		// 이동이 모두 끝난 뒤,
		// 2개 이상의 파이어볼이 있는 칸에서는 다음과 같은 일이 일어난다.
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				
				if (map[i][j].size() == 1){
					fire.push_back(map[i][j][0]);
				}
				else if(map[i][j].size() >= 2) {
					// 두개 이상의 파이어볼 존재
					int weight = 0;
					int speed = 0;
					bool is_odd = true; bool is_even = true;

					for(int m=0; m<map[i][j].size(); m++) {
						weight += map[i][j][m].m;
						speed += map[i][j][m].s;

						if(map[i][j][m].d % 2 != 0)
							is_even = false;
						else
							is_odd = false;
					}
					weight = weight / 5;
					speed = speed / int(map[i][j].size());

					if(weight < 1)
						continue;

					if(is_odd || is_even) {
						// 0246
						Fire f1, f2, f3, f4;
						f1.d = 0; f2.d = 2; f3.d = 4; f4.d = 6;
						f1.s = speed; f2.s = speed; f3.s = speed; f4.s = speed;
						f1.m = weight; f2.m = weight; f3.m = weight; f4.m = weight;
						f1.y = i; f2.y = i; f3.y = i; f4.y = i;	
						f1.x = j; f2.x = j; f3.x = j; f4.x = j;					

						fire.push_back(f1);
						fire.push_back(f2);
						fire.push_back(f3);
						fire.push_back(f4);
					}
					else {
						// 1357
						Fire f1, f2, f3, f4;
						f1.d = 1; f2.d = 3; f3.d = 5; f4.d = 7;
						f1.s = speed; f2.s = speed; f3.s = speed; f4.s = speed;
						f1.m = weight; f2.m = weight; f3.m = weight; f4.m = weight;
						f1.y = i; f2.y = i; f3.y = i; f4.y = i;	
						f1.x = j; f2.x = j; f3.x = j; f4.x = j;					

						fire.push_back(f1);
						fire.push_back(f2);
						fire.push_back(f3);
						fire.push_back(f4);
					}
				}
				
			}
		}		

	
	}

	return;
	
}


int main() {

	scanf("%d %d %d", &n, &m, &k);

	for(int i=0; i<m; i++) {
		Fire tmp;
		scanf("%d %d %d %d %d", &tmp.y, &tmp.x, &tmp.m, &tmp.s, &tmp.d);
		tmp.y--; tmp.x--;
		fire.push_back(tmp);
	}

	solve();

	count();

	printf("%d\n", res);





}