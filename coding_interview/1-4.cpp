#include <iostream>
#include <cstring>
using namespace std;

bool solve(string a) {
	int len = a.size()-1;

	for(int i=0; i<a.size()-2; i++) {
		char front = a[i];
		char back = a[len-i];

		if(front != back)
			return false;
	}

	return true;

}

int main() {
	//string a = "abccba";
	string a = "atco cta";

	bool answer = solve(a);

	if(answer)
		printf("palindrome");
	else
		printf("no");
}
