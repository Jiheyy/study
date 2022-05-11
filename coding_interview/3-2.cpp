#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void push(vector <unordered_set>& v, int no) {
	v.push(no);
}

void pop(vector <uno> &V) {

	int head = v[v.size()-1];
	cout << head <<endl;

	v.erase(v.size()-1);
}


void min()


int main() {

	vector <int> v;

	push(v, 1);
	push(v, 3);
	push(v, 5);
	pop(v);

	cout << min(v) <<endl;


}