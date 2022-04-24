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

int solve(linked_list list, int k) {
	node *front, *end;
	front = end = list.first();


	for(int i=0; i<k; i++) {
		end = end->next;
		if(end == NULL) return front->data;
	}

	while(end != NULL) {
		end = end->next;
		front = front->next;
	}
	return front->data;
}


int main()
{
	solve(list, k);

}