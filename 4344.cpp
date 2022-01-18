#include <iostream>
#include <vector>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);

	while(c--) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		vector <int> v;
		for(int i=0; i<n; i++) {
			int score;
			scanf("%d", &score);
			sum += score;
			v.push_back(score);
		}

		double ave = sum / n;
		double count = 0.0;
		for(int i=0; i<n; i++)
			if(v[i] > ave)
				count++;

		printf("%.3f%%\n", (count / n) * 100); 
	}
}