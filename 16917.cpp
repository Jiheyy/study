#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c, x, y;
	int res = 987654321;

	scanf("%d %d %d %d %d",&a, &b, &c, &x, &y);


	for(int i=0; i<=max(x, y); i++) {
		int yang =x-i;
		int fri = y-i;
		if(yang < 0) yang = 0;
		if(fri < 0) fri = 0;
		
		int tmp = a* (yang) + b* (fri) + 2*c*i;
		res = min(res, tmp);
	}
	printf("%d\n", res);
}
