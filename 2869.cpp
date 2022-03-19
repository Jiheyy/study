#include <iostream>
using namespace std;
int main() {
	int a, b, v;

	cin >> a>>b>>v;

	int cur = 0;
	int d = 0;

	for(d=0;v>cur; d++) {
		if(cur + a >= v)
			break;
		cur += (a-b);
	}

	printf("%d\n", d+1);
}