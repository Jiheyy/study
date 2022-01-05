#include <iostream>

int n, k, res;
int a[200];

void solve() {
	int zero_cnt= 0;
	int robot[200*1000];
	int front = 0, back=0; 

	while(zero_cnt < k) {
		res++;

		// 컨테이너 회전
		int temp = a[2*n -1];
		// 끝값부터 이동
		for(int i=2*n-1; i>=1; i--) {
			a[i] = a[i-1];
		}
		a[0] = temp;

		// 로봇 회전 (queue 성질)
		for(int i=front; i<back; i++){
			++robot[i];
			if(robot[i]== n-1) {
				++front;
			}
		}

		for(int i=front; i<back; i++) {
			int next = robot[i] +1;
			if(a[next] == 0 || (i!= front && robot[i-1] == next)) 
				continue;

			robot[i] = next;
			a[next]--;
			if(robot[i] == n-1) {
				front++;
			}
			if(a[next] == 0)
				zero_cnt++;
		}

		// put new robot
		if(a[0] > 0 && (back == 0 || robot[back-1]!=0)) {
			robot[back++] = 0;
			a[0]--;
			if(a[0] == 0)
				zero_cnt++;
		}
	}
}


int main() {

	scanf("%d %d", &n, &k);

	for(int i=0; i<2*n; i++)
		scanf("%d", &a[i]);

	solve();

	printf("%d\n", res);
}