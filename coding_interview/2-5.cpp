#include <iostream>
#include "LinkedList.h"

linked_list SumTwoList(linked_list list1, linked_list list2) {

	node *cur1 = list1.first();
	node *cur2 = list2.first();
	linked_list res;
	bool up = false;
	while(cur1 != NULL && cur2 != NULL) {
		int sum = cur1->data + cur2->data;
		if(up)
			sum+=1;

		if(sum < 10) {
			res.add_node(sum);
			up = false;
		}
		
		else {
			res.add_node(sum-10);
			up = true;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	while(cur1 != NULL) {
		res.add_node(cur1->data);
		cur1 = cur1->next;
	}
	while(cur2 != NULL) {
		res.add_node(cur2->data);
		cur2 = cur2->next;
	}

	return res;
}

int main() {
	linked_list list1;
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);
	
	list1.printLinkedList();

	linked_list list2;
	list2.add_node(5);
	list2.add_node(9);
	list2.add_node(2);
	
	list2.printLinkedList();

	SumTwoList(list1, list2).printLinkedList();
}