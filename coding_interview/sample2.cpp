#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;


class Stack {
private:
	stack <int> s;
	stack <int> s2;
	int min_value = 9999;
public:
	void push(int ele) {
		s.push(ele);
		if(ele <= min_value) {
			s2.push(ele);
			min_value = ele;
		}
	}

	int pop() {
		int no = s.top();
		if(no == min_value) {
			s2.pop();
			min_value = s2.top();
		}
		s.pop();
		return no;
	}

	int min() {
		int value = s2.top();
		s2.pop();
		return value;
	}
};

int main() {

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout <<s.min() <<endl;



}