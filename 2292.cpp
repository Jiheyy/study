#include <iostream>
#include <vector>
using namespace std;

int main() {

	unsigned long long n;
	cin >> n;

	int i=0; 
	unsigned long long level = 1;


	if(n == 1)  {
		printf("1\n");
		return 0;
	}

	while(true) {
		i += level * 6;
		if(i >= n)
			break;

		level++;
	}

	printf("%llu\n", level+1);

	
}