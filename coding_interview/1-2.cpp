#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int visit[128];

bool solve1(string a, string b) {
	
	if(a.size() != b.size())
		return false;

	for(auto alphabet : a) {
		visit[alphabet]++;
	}
	for(auto alphabet : b) {
		visit[alphabet]--;
	}

	for(int i=0; i<128; i++) {
		if(visit[i] != 0)
			return false;
	}

	return true;
}


int main() {
	string a = "dog";
	string b = "god";

	bool answer;

	answer = solve1(a, b);

	if(answer)
		printf("order exist");
	else
		printf("no order");
}