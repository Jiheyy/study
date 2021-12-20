#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 

// 순열
int n;
int arr[12];
vector <int> op;
int min_answer, max_answer;


int main() {


	min_answer = 987654321;
	max_answer = -987654321;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<4; i++) {
		int operate;
		scanf("%d", &operate);

		for(int j=0; j<operate; j++) {
			op.push_back(i);
		}
	}

	sort(op.begin(), op.end());
	do {

		int result = arr[0];
		for(int i=0; i<op.size(); i++) {
			int b = arr[i+1];
			int oper = op[i];

			if(oper == 0) {
				result += b;
			}
			else if (oper == 1) {
				result -= b;
			}
			else if (oper == 2) {
				result *= b;
			}
			else {
				result /= b;
			}
		}
		min_answer = min(min_answer, result);
		max_answer = max(max_answer, result);


	}while(next_permutation(op.begin(), op.end()));


	printf("%d\n%d\n", max_answer, min_answer);

	return 0;
}