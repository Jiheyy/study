#include <iostream>
#include <cstring>

using namespace std;

int main() {

	string form = "";
	cin >> form;

	int res = 0;

	if(form[0] == 'd')
		res = 10;
	else if(form[0] == 'c')
		res = 26;

	for(int i=1; i< form.length(); i++) {

		if(form[i] == 'd') {
			// compare with before value
			if(form[i-1] == 'd')
				res *= 9;
			else
				res *= 10;

		}
		else if(form[i] == 'c') {
			// compare with before value
			if(form[i-1] == 'c')
				res *= 25;
			else
				res *= 26;
		}
	}

	printf("%d\n", res);

	return 0;
}