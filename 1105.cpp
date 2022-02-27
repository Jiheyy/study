#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string L, R;

int main() {

	cin >> L >> R;

	
	if(L.size() != R.size()) {
		printf("0\n");
		return 0;
	}
	int answer = 0;
	for(int i=0; i<L.size(); i++) {

		if(L[i] == R[i] && R[i] == '8')
			answer++;
		else if(L[i] != R[i])
			break;
	}
	printf("%d\n", answer);
	return 0;
}