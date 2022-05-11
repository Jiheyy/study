#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void sort(stack <int>& s) {

	stack <int> ns;

	while(!s.empty()) {
		int value = s.top();

		if(!ns.empty() && value < ns.top()) {
			s.push(ns.top());
		} else {
			while(!ns.empty() && ns.top() <= value) {
				s.push(ns.top());
				ns.pop();
			}
		}
		ns.push(value);
	}
}

int main() {
	stack <int> s;

	s.push(3);
	s.push(2);
	s.push(5);


	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}

}