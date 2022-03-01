#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int A[1000];
int answer;
int DP[1000];

void dp(int n) {

	int max_value = 0;
	for(int i=0; i<n; i++) {
		if(A[n] > A[i]) {
			max_value = max(max_value, DP[i]);
		}
	}

	DP[n] = max_value + 1;

	answer = max(DP[n], answer);

}


int main () {
	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%d", &A[i]);

	DP[0] = 1;
	answer = 1;
	for(int i=1; i<n; i++) {
		dp(i);
	}

	printf("%d\n", answer);
}