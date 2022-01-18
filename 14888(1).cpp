#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MIN = 987654321;
int MAX = -987654321;
int n;
int no[11];
vector <int> v;

int main() {
	scanf("%d", &n);
	
	for(int i=0; i<n; i++)
		scanf("%d", &no[i]);

	for(int i=0; i<4; i++) {
		int t;
		scanf("%d", &t);
		for(int j=0; j<t; j++) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());
	do {
		int answer = no[0];
		for(int i=1; i<n; i++) {
			if(v[i-1] == 0)
				answer += no[i];
			else if(v[i-1] == 1)
				answer -= no[i];
			else if(v[i-1] == 2)
				answer = answer *no[i];
			else if(v[i-1] == 3)
				answer /= no[i];
			//printf("%d: %d\n",v[i-1], answer);

		}
		//printf("\n%d\n", answer);

		if(answer > MAX)
			MAX = answer;
		if (answer < MIN)
			MIN = answer;

	}while (next_permutation(v.begin(), v.end()));

	printf("%d\n%d\n",MAX, MIN);


}