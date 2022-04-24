#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool solve(string s1, string s2) {
	
	for(int i=0; i<s2.size(); i++) {
		string tmp = s2.substr(i) + s2.substr(0, i);
		cout << tmp <<endl;
		tmp = tmp.substr(0, s1.size());
		
		if(tmp == s1) {
			if(isSubstring(tmp, s1)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	bool answer = solve(s1, s2);

	cout<< answer;

	
}