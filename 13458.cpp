#include <iostream>
#include <vector>
#include <cmath>
using namespace std;



long long solve(long long total, long long b, long long c) {
	long long a = total;
	long long ret = 0;

	// 시험관은 한명만 가능하다는 조건 명심
	if(a - b <= 0) ret+= 1;

	else if((a-b)%c == 0)
		ret += (a-b) / c + 1;

	else ret += (a-b) / c +2;

	return ret;
}


int main() {
	long long res = 0;
	int n, b, c;
	vector <int> classes;
	scanf("%d", &n);

	while(n--) {
		int a;
		scanf("%d", &a);
		classes.push_back(a);
	}

	scanf("%d %d", &b, &c);


	for(int i=0; i<classes.size(); i++) {
		res += solve(classes[i], b, c);
	}

	printf("%lld\n", res);
}