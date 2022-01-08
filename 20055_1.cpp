#include <iostream>
using namespace std;

int n, k, res;
int map[200];

void solve() {

	int zero_cnt = 0;
	int start = 0; int end = 0;

	int robot[200 * 2000];

	while(zero_cnt < k) {
		res++;

		int last = map[2*n-1];
		for(int i=2*n-1; i>=1; i--) {
			map[i] = map[i-1];
		}
		map[0] = last;

		for(int i=start; i<end; i++) {
			robot[i]++;
			if(robot[i] == n-1)
				start++;
		}

		for(int i=start; i<end; i++) {
			int next = robot[i]+1;
			if((i == start || next != robot[i-1]) && map[next] >= 1) {
				robot[i]++;
				map[next]--;
				if(map[next] == 0)
					zero_cnt++;
			}
			if(robot[i] == n-1)
				start++;
		}

		if(map[0] != 0) {
			robot[end] = 0;
			end++;
			map[0]--;
			if(map[0] == 0)
				zero_cnt++;
		}

	}
}


int main() {

	scanf("%d %d", &n, &k);

	for(int i=0; i<2*n; i++)
		scanf("%d", &map[i]);

	solve();

	printf("%d\n", res);
}