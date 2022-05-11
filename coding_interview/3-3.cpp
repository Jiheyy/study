#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class SetOfStacks {
private:
	int max;
	stack <int> s[50];
	int file_cnt;
public:
	SetOfStacks(int value) {
		max = value;
		file_cnt = 0;
	}


	void push(int ele) {

		if(s[0].size() < max) {	
			s[file_cnt].push(ele);
		}
		
		else {
			stack <int> next;
			next.push(ele);
			file_cnt++;
			s[file_cnt] = next;
		}
		
	}

	void pop() {
		int top = s[file_cnt].top();
		cout << top <<endl;
		s[file_cnt].pop();
	}
};



int main() {
	SetOfStacks s(3);
	
	s.push(1);
	s.push(2);
	s.push(3);
	
	s.push(4);
	s.push(5);
	s.push(6);
	
	s.pop();
	
}