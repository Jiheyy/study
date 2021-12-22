#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 시간초과
int main() {
	int n;
	vector <int> v;

	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);

		sort(v.begin(), v.end());

		printf("%d\n", v[i/2]);
	}

}