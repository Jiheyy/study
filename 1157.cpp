#include <iostream>
#include <map>
#include <cstring>
using namespace std;

map <char, int> m;
int max_repeat;

int main() {
	string word = "";
	cin >> word;

	for(auto letter: word) {
		if(letter >= 'a')
			letter = toupper(letter);
		if(m.find(letter) == m.end()) {
			m.insert(make_pair(letter, 0));
		}

		if(++m[letter] > max_repeat){
			max_repeat = m[letter];
		}
	}
	//printf("max : %d\n", max_repeat);

	bool exist = false;
	string max_letter = "";
	for(auto M: m) {
		//cout << M.first << M.second <<endl;
		if(M.second == max_repeat) {
			if(exist == true) {
				printf("?");
				return 0;
			}
			exist = true;
			max_letter = M.first;
		}
	}
	cout << max_letter;
}