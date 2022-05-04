#include <iostream>
#include "LinkedList.h"

void DeleteInsideNode(node* head) {

	if(head->next == NULL)
		return;
	
	node *node = head ->next;

	node->data = node->next->data;
	node->next = node->next->next;
}

int main() {
	linked_list list;
	list.add_node(1);
	list.add_node(2);
	list.add_node(1);
	list.add_node(4);
	list.add_node(4);
	list.add_node(1);
	list.add_node(5);

	list.printLinkedList();
	DeleteInsideNode(list.first());
	list.printLinkedList();
}