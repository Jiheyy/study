#include <iostream>
#include <stack>
#include <queue>
using namespace std;


class STACK {
private:
	stack <int> s1;
	stack <int> s2;
public:

	void pop() {

		while(!s1.empty()) {
			int top = s1.top();
			s1.pop();
			s2.push(top);
		}
		cout << s2.top() <<endl;
		s2.pop();

		while(!s2.empty()) {
			int top = s2.top();
			s2.pop();
			s1.push(top);
		}
	}

	void push(int ele) {
		s1.push(ele);

	}
};

int main() {
	STACK s;
	queue <int> q;
	for(int i=0; i<10; i++) {
		s.push(i);
		q.push(i);
	}

	s.pop();
	cout << q.front() <<endl;
}