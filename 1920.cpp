#include <iostream>
#include <map>

using namespace std;

map <int, int> m;

int main() {
	int n;

	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		m[tmp] = 1;
	}

	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if(m[tmp] != 0)
			printf("1\n");
		else
			printf("0\n");
	}

}