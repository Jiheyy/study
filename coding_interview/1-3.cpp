
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char ret[100];

void solve(string str, int no) {

	int idx = 99;
	for(int i=no-1; i>=0; i--) {
		if(str[i] == ' ') {
			ret[idx] = '0';
			ret[idx-1] = '2';
			ret[idx-2] = '%';
			idx-=3;
		}
		else{
			ret[idx] = str[i];
			idx--;
		}

	}

	for(int i=idx; i<=99; i++) {
		printf("%c", ret[i]);
	}

}


int main() {

	string a = "Mr John Smith";
	int no = 13;

	solve(a, no);

}