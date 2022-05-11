#include <iostream>
#include <stack>
#include <set>

using namespace std;

class STACK {
private:
	stack <int> s;
	set <int> m;
public:

	int pop() {
		int no = s.top();
		s.pop();
		return no;
	}

	void push(int ele) {
		s.push(ele);
		m.insert(ele);
	}

	int min() {
		int value = *m.begin();
		m.erase(value);
		return value;
	}
};

int main() {

	STACK st;
	st.push(1);
	st.push(2);
	st.push(-1);

	cout << st.min();


}