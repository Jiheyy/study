#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;
bool arr[10001];

void kaprekar(int n) {

	if(n >= 10000)
		return;

	int res = n;

	while(n!= 0) {
		res += (n % 10);
		n = n / 10;
	}
	if(res > 10000)
		return;
	arr[res] = true;
	kaprekar(res);
}


int main() {

	int no = 0;
	vector <int> self_no;
	while (++no <= 10000) {
		if(arr[no] == false) {
			self_no.push_back(no);
			kaprekar(no);
		}
	}
	
	for(int i=0; i<self_no.size(); i++)
		printf("%d\n", self_no[i]);
	
	return 0;
}