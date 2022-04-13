#include <iostream>
#include <cstdlib> 
#include <cstring>
using namespace std;

int visit[128];
int cmp(string a, string b) {
	int cnt = 0;

	for(auto ele: a) {
		visit[ele]++;
	}

	for(auto ele: b){
		visit[ele]--;
	}

	for(int i=0; i<128; i++) {
		if(visit[i] != 0)
			cnt++;
	}
	return cnt;
}

bool solve(string a, string b) {

	int diff = a.size() - b.size();
	diff = abs(diff);

	if(diff >= 2)
		return false;

	// 삽입 한회 가능
	if(diff == 1) {
		if(cmp(a, b) == 1)
			return true;
		else
			return false;
	}

	if(cmp(a, b) == 2)
		return true;

	return false;

}


int main() {
	string a = "pale";
	string b = "bake";
	bool answer = solve(a, b);

	if(answer)
		printf("success");
	else
		printf("fail");
}