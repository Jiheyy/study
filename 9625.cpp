#include <iostream>
#include <vector>
using namespace std;

pair <int, int> DP[50];
int k;

int main() {
	scanf("%d", &k);

	DP[0].first = 1;
	DP[0].second = 0;

	for(int i=1; i<=45; i++) {

		int x = DP[i-1].first; // 이전에 a의 갯수
		int y = DP[i-1].second; // 이전에 b의 갯수

		int new_x = y;
		int new_y = x + y; 
		DP[i].first  = new_x;
		DP[i].second = new_y;
	}

	printf("%d %d\n", DP[k].first, DP[k].second);
}
