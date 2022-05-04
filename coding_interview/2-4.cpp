#include <iostream>
#include "LinkedList.h"


void divisionBasedOnX(linked_list& list, int x) {

	linked_list small;
	linked_list big;
	
	node *cur = list.first();
	while(cur != NULL) {
		int data = cur->data;
		if(data < x) {
			small.add_node(data);
		}
		else
			big.add_node(data);

		cur = cur->next;
	}
	node *last = small.last();
	last->next = big.first();
	list = small;
}

int main() {
	linked_list list;
	list.add_node(3);
	list.add_node(2);
	list.add_node(1);
	list.add_node(5);
	list.add_node(4);
	list.add_node(4);
	list.add_node(1);
	list.add_node(5);
	list.add_node(6);
	list.add_node(8);
	list.add_node(1);
	list.add_node(2);
	list.add_node(7);

	list.printLinkedList();
	divisionBasedOnX(list, 5);
	list.printLinkedList();
}