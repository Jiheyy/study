#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v = {1, 2, 3, 9, 10, 0, 5};
	sort(v.begin(), v.end());
	
	vector <int>::iterator it = lower_bound(v.begin(), v.end(), 4);
	cout << *it << " idx: " << it - v.begin() <<endl;
} 
	
