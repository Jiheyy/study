#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct Dragon {
	int x, y, d, g;
};

int n, res;
vector <Dragon> dragon;
int map[101][101];

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1 ,0};



void solve() {

	for(int i=0; i<dragon.size(); i++) {

		int curve_size = 0;
		int curve[1025] = {0, };

		// check start point
		Dragon d = dragon[i];
		int new_y = d.y;
		int new_x = d.x;
		int new_d = d.d;
		curve[curve_size++] = d.d;
		map[new_y][new_x] = 1;

		for (int j=0; j<d.g; j++) 
			for(int k=curve_size-1; k>=0; k--) {
				curve[curve_size++] = (curve[k] +1) % 4;
			}

		//printf("curve_size : %d\n", curve_size);
		for(int j=0; j<curve_size; j++) {
			new_y += dy[curve[j]];
			new_x += dx[curve[j]];
			
			//printf("%d %d\n", new_y, new_x);

			if(new_y < 0 || new_y >= 101|| new_x < 0 || new_x >= 101) continue;

			map[new_y][new_x] = 1;
		}
		
	}

}
/*
3
3 3 0 1
4 2 1 3
4 2 2 1
*/
void count_box() {

	printf("---------\n");
	printf("0 1 2 3 4 5 6\n");
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

    for (int y = 0; y < 100; ++y) {
        for (int x = 0; x < 100; ++x) {
            if (map[y][x] && map[y][x + 1] && map[y + 1][x] && map[y + 1][x + 1]) {
                ++res;
            }
        }
    }

}

int main() {
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		Dragon tmp;
		scanf("%d %d %d %d" , &tmp.x, &tmp.y, &tmp.d, &tmp.g);
		dragon.push_back(tmp);
	}

	solve();
	count_box();

	printf("%d\n", res);


}

