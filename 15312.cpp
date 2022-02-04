#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int alphabet[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
string name[2];
vector <int> v;


int main() {

	for(int i=0; i<2; i++) {
		cin >> name[i];
	}

	for(int i=0; i<name[0].length(); i++) {
		v.push_back(alphabet[name[0][i] - 'A']);
		v.push_back(alphabet[name[1][i] - 'A']);
	}

	while(v.size() > 2) {

		vector <int> nv;
		nv.clear();

		for(int i=0; i<v.size()-1; i++) {
			nv.push_back((v[i] + v[i+1]) % 10);
		}

		v = nv;
	}

	for(auto ele: v)
		printf("%d", ele);


	return 0;
}