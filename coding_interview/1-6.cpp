#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {

	string a = "aabcccccaaa";

	char key = a[0];
	int cnt = 1;
	string answer = "";
	for(int i=1; i<a.size(); i++) {
		char ele = a[i];

		if(ele != key) {
			answer += key + to_string(cnt);
			cnt = 1;
			key = ele;
		}
		else {
			cnt++;
		}
	}
	if(answer.size() > a.size())
		cout << a <<endl;
	else
		cout << answer <<endl;
}