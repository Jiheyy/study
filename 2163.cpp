#include <iostream>
#include <vector>

using namespace std;
int answer;

void divide_i(int x) {
	if(x == 1)
		return;

	else {
		answer++;
		divide_i(x/2);
		divide_i(x-x/2);
	}
}

void divide_j(int y, int x) {
	if(y == 1) {
		if(x != 1) {
			answer++;
			divide_i(x/2);
			divide_i(x - x/2);
		}
		return;
	}

	else {
		answer++;
		divide_j(y/2, x);
		divide_j(y - y/2, x);
	}
}




int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	if(n != 1) {
		answer++;
		divide_j(n/2, m);
		divide_j(n - n/2, m);
	}
	else if(m != 1) {
		answer++;
		divide_i(m/2);
		divide_i(m - m/2);
	}

	printf("%d\n", answer);
	return 0;
}