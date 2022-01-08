#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	intcnt;

	scanf("%d", &cnt);
	vector <int> a(cnt);

	for(int i=0; i<cnt; i++)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());

	printf("%d\n", a[0] * a[cnt-1]);
}