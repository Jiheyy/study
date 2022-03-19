#include <iostream>
#include <cstring>
using namespace std;

int main() {

	while(true) {
		string str = "";
		cin >> str;

		if(str == "0") {
			return 0;
		}
		int length = str.size();
		bool success = true;
		for(int i=0; i<length/2; i++) {
			if(str[i] != str[length-1-i]) {
				printf("no\n");
				success = false;
				break;
			}
		}
		if(success)
			printf("yes\n");
	}
}