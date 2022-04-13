#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int visit[128];

bool solve(string str) {

	string a = "";

	for(auto ele : str) {
		if(ele != ' ')
			a+= ele;
	}

	int len = a.size();

	for(int i=0; i<str.size(); i++) {
		visit[str[i]]++;
	}

	int cnt = 0;
	for(int i=0; i<128; i++)
		if(visit[i]%2 != 0)
			cnt++;

	if(cnt <= 1)
		return true;
	
	return false;

}


int main () {
	string a = "tactcoapapa";

	if(solve(a))
		cout << "true" <<endl;
	else
		cout << "false";

}