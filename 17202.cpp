#include <iostream>
#include <vector>
using namespace std;

int no[2][10];
vector <int> v;


int main() {

	for(int i=0; i<2; i++) {
		for(int j=0; j<8; j++) {
			scanf("%1d", &no[i][j]);
		}
	}

	for(int i=0; i<8; i++) {
		v.push_back(no[0][i]);
		v.push_back(no[1][i]);
	}


	while(v.size() > 2) {

		vector <int> nv;
		nv.clear();

		for(int i=0; i<v.size()-1; i++) {
			nv.push_back((v[i]+v[i+1]) % 10);
		}

		v = nv;
	}

	for(auto ele: v)
		printf("%d", ele);


	return 0;
}