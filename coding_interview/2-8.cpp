#include "LinkedList.h"
#include <iostream>
using namespace std;

int LoopCheck(linked_list& list) {
	node *cur1 = list.first();
	node *cur2 = list.first();


	while(cur1 != NULL && cur2 != NULL) {
		cur1 = cur1->next;
		cur2 = cur2->next->next;
		if(cur1 == cur2) break;
	}

	if(cur1 == NULL || cur2 == NULL)
		return -1;

	cur1 = list.first();
	while(cur1 != cur2) {
		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	return cur1->data;
}

int main() {
	linked_list list1;
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);
	list1.add_node(7);
	list1.add_node(1);
	list1.add_node(6);


	list1.last()->next = list1.first();	



	cout << LoopCheck(list1) <<endl;
}