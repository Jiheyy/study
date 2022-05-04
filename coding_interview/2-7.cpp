#include <iostream>
#include "LinkedList.h"
using namespace std;

linked_list Duplicate(linked_list list1, linked_list list2) {

	node *cur1 = list1.first();
	node *cur2 = list2.first();

	bool start = false;

	while(cur1 != NULL) {
		linked_list res;

		bool start = false;
		while(cur2 != NULL) {
			int data1 = cur1->data;
			int data2 = cur2->data;

			if(data1 != data2) {
				cur2 = cur2->next;
				continue;
			}
			else {
				start = true;
				res.add_node(data1);
				cur2 = cur2->next;
				cur1 = cur1->next;
			}
		}
		if(start == false)
			cur1 = cur1->next;
		else
			return res;
	}
	linked_list empty;
	return empty;
}

int main() {
	linked_list list1;
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);
	
	//list1.printLinkedList();

	linked_list list2;
	list2.add_node(7);
	list2.add_node(7);
	list2.add_node(1);
	list2.add_node(6);
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);
	
	//list2.printLinkedList();

	Duplicate(list1, list2).printLinkedList();
}