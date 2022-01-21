#include <iostream>
#include <vector>
#include <algorithm>
// 시간초과
using namespace std;
int N;


int main() {
	scanf("%d", &N);

	vector <long long> v;
	for(int i=0; i<N; i++) {
		long long tmp;
		scanf("%lld", &tmp);
		v.push_back(tmp);
	}

	do {
		bool success = true;

		for(int i=1; i<N; i++) {
			long long before = v[i-1];
			long long cur = v[i];		
			if(before * 2 != v[i] && (before % 3 != 0 || before /3 != v[i])){
				success = false;
				break;
			}

		}

		if(success) {
			for(auto b: v)
				printf("%lld ", b);
			exit(0);
		}


	}while(next_permutation(v.begin(), v.end()));
	
}