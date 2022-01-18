#include <iostream>
#include <vector>
#include <algorithm>

// 시간초과
// 십진수를 이진수로 바꾸는것임
using namespace std;
int n, k;

bool binary (int n) {
	
	int cnt = 0;

	while(n > 0) {
		if(n%2 == 1)
			cnt++;

		n/=2;
	}

	if (cnt <= k)
		return true;
	return false;
}


int main() {

	scanf("%d %d", &n, &k);

	int no = n;
	while(true) {

		if(binary(no))
			break;
		no++;
	}

	printf("%d\n", no-n);


}