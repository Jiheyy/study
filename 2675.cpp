#include <cstring>
#include <iostream>
using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	while(t--) {
		int r;
		string word;

		scanf("%d", &r);
		cin >> word;

		for(auto w: word) {
			for(int i=0; i<r; i++) {
				cout << w;
			}
		}
		cout <<'\n';
	}
}