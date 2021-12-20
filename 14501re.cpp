#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int n, answer;
int t[30];
int p[30];
int cache[30];


int DP(int i) {

	if(i > n) {
		return 0;
	}

	if(cache[i] != -1)
		return cache[i];

	if(i+t[i] <= n+1)
		cache[i] = DP(i+t[i])+p[i];
	
	cache[i] = max(cache[i], DP(i+1));

	return cache[i];
	
}


int main(int argc, char** argv) {

	memset(cache, -1, sizeof(cache));


	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		scanf("%d %d", &t[i], &p[i]);
		
	}

	answer = DP(1);

	printf("%d\n", answer);
	return 0;

}