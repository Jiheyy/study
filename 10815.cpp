#include <iostream>
#include <map>
using namespace std;

bool pos[10000000];
bool neg[10000000];

int main() {
	int n;
	scanf("%d", &n);

	while(n--) {
		long long no;
		scanf("%lld", &no);
		if(no >= 0)
			pos[no] = true;
		else
			neg[-no] = true;
	}	

	int m;
	scanf("%d", &m);
	while(m--) {
		int no;
		scanf("%d", &no);

		if(no >=0 && pos[no] == true)
			printf("1 ");
		else if(no < 0 && neg[-no] == true)
			printf("1 ");

		else
			printf("0 ");
	}


}