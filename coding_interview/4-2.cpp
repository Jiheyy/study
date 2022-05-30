#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int arr[10];

map<int, pair<int, int>> tree;


int find_mid(int start, int end) {

	if(start == end || start < 0 || end > 10) 
		return 9999;
	//cout <<"mid" << arr[(start+end)/2] <<endl;
	return arr[(start+end)/2];
}

// get mid value
void insert(int start, int end) {

	
	if(start == end) return;

	int value = find_mid(start, end);
	if(value == 9999) return;

	if(tree.find(value) != tree.end()) {
		tree[value] = make_pair(9999, 9999);
	}
	else {
		int mid = (start + end) /2;
		int left = find_mid(start, mid-1);
		int right = find_mid(mid, end);
		if(left != 9999)  {
			cout << value <<"L->"<< left <<endl;
			tree[value].first = left;
			insert(start, mid);
		}
		if(right != 9999) {
			cout << value <<"R->"<< right <<endl;
			tree[value].second = right;
			insert(mid, end);
		}
	}
}



int main() {

	

	for(int i=0; i<10; i++)
		arr[i] = i;
	insert(0, 10);

	//insert(0, 10, v, btree.Root(), true);
}