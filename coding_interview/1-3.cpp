#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


string solve(string a, int len) {
	string ret = "";
	vector <string> v;

	for(int i=a.size(); i>=0; i--) {
		string alphabet;
		alphabet += a[i];
		if(a[i] == ' ') {
			v.push_back("%20");
		}
		else
			v.push_back(alphabet);
	}

	for(int i=v.size()-1; i>=0; i--) {
		ret += v[i];
	}

	return ret;
}


int main() {

	string a = "Mr. John Smith";
	int len = 13;

	string answer = solve(a, len);

	cout << answer <<endl;

}