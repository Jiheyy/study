#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main () {
	int n;
	scanf("%d", &n);

	while(n--) {
		string answer;
		cin >> answer;
		int cnt = 0;
		int total = 0;
		for(auto a: answer) {
			if(a == 'O')
				cnt++;
			else if(a == 'X')
				cnt = 0;
			total += cnt;
		}
		printf("%d\n", total);
	}
}