#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string A;
    int word = 0;
	while(true) {
		cin >> A;
		if (A == '\n')
			break;
    
    for(auto a: A) {
		cout << a << endl;
        if(a == ' ' || a == '\n')
            word++;
    }
    printf("%d\n", word);
}
