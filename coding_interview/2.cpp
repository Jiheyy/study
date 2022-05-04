#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

class link {
private:
	node *head, *tail;
public:
	link() {
		head = NULL;
		tail = NULL;
	}

	void add(int n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		if(head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = NULL;
		}
	}
	node * first() {
		return head;
	}
}

void solve(link list) {
	if(list.first() == NULL) return;
	node *cur = list.first();
	node *target, prev;

	while(true) {
		target = cur->next;
		prev = cur;

		while(true) {
			if(target->data == prev->data) {
				// remove
				prev->next = target->next;

			}
			else {
				prev = target;
			}
			// 끝
			if(target->next == NULL)
				break;
		}
		if(cur->next == NULL)
			break;
		cur = cur->next;
	}


}

int main() {


	solve(list);

}