#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool check[51];

struct PARTY {
	vector <int> v;
};

vector <PARTY> party;

void checker(vector <int> v) {
	bool exist = false;

	for(auto ele : v) {
		if(check[ele] == true) {
			exist = true;
			break;
		}
	}
	if(exist) {
		for(auto ele : v)
			check[ele] = true;
	}
}

int main() {
	int n,m;
	scanf("%d %d", &n, &m);

	int no;
	scanf("%d", &no);

	while(no--) {
		int tmp;
		scanf("%d", &tmp);
		check[tmp] = true;
	}

	for(int i=0; i<m; i++) {
		PARTY p;
		p.v.clear();
		int cnt;
		scanf("%d", &cnt);

		for(int j=0; j<cnt; j++) {
			int no;
			scanf("%d", &no);
			p.v.push_back(no);
			checker(p.v);
		}
		party.push_back(p);
	}

	int answer = 0;
	for(auto p: party) {
		bool attend = true;
		for(auto ele : p.v) {
			if(check[ele] == true) {
				attend = false;
				break;
			}
		}	
		if(attend)
			answer++;
	}

	printf("%d\n", answer);

	return 0;
}