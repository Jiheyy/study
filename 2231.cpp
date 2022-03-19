#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for(int i=1; i<=n; i++) {
		int sum = i;
		int no = i;
		
		while(no) {
			sum += no % 10;
			no /= 10;
		}

		if(sum == n) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
}