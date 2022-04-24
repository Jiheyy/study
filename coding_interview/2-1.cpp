#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node *next;
};


class linked_list {
private:
	node *head, *tail;
public:
	linked_list() {
		head = NULL;
		tail = NULL;
	}
	void add_node(int n) {
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		if(head == NULL) {
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tail->next; 
		}
	}
	node* first() {
		return head;
	}
}

int solve(linked_list list) {
	if(list.first() == NULL) return;

	node *cur = list.first();
	node *target, * prev;

	while(true) {
		target = cur->next;
		prev = cur;

		while(true) {
			if(target->data == cur->data) {
				prev->next == target->next;
			}
			else {
				prev = target;
			}
			if(target->next == NULL) break;
			target = target->next;
		}
		if(cur->next == NULL)break;
		cur = cur->next;
	}
	
}


int main()
{
	solve(list);

}