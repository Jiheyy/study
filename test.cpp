#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	queue <int> q;
    q.push(1);
    q.push(2);
    
    while(!q.empty()) {
    	int value = q.front();
    	q.pop();
        printf("%d\n", value); // 1, 2
    }
    
    stack <int> s;
    s.push(1);
    s.push(2);
    
    while(!s.empty()) {
    	int value = s.top();
    	s.pop();
        printf("%d\n", value); // 2, 1
    }
    
    
}
