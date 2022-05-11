#include <iostream>
#define MAX 999
using namespace std;

int arr[999];

class SetOfStacks {
private:
	int no;
	int start_idx;
	int end_idx;

public:
	SetOfStacks(int no) {
		start_idx = MAX/3 * no;
		end_idx = start_idx;
	}

	void push(int ele) {
		arr[end_idx] = ele;
		end_idx++;		
	}

	void pop() {
		cout << arr[end_idx-1];
		end_idx--;
	}
};


int main() {

	SetOfStacks s1(0);

	s1.push(1);
	s1.push(2);
	s1.push(3);

	SetOfStacks s2(1);

	s2.push(4);
	s2.push(5);
	s2.push(6);

	s1.pop();
	s2.pop();

}