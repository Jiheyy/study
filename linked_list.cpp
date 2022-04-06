#include <iostream>
#include <list>

using namespace std;

int main() {

	list <int> b;

	// 링크드리스트는 at 등의 함수가 없어서 
	// 중간에 십입을 해야할 경우 iterator 를 사용해 주어야한다.
	list <int>:: iterator iter = b.begin();

	for(int i=0; i<5; i++)
		b.push_back(i);
	// 0, 1, 2, 3, 4

	b.pop_back(); // 0, 1, 2, 3
	b.pop_front(); // 1, 2, 3

	iter = b.begin(); 
	int k = 2;
	for(int i=0; i<k-1; i++) {
		++iter;
	}
	b.insert(iter, 8);

	for(auto value : b) {
		cout << value<< " ";
	}
	

	return 0;
}