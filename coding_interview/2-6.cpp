#include <iostream>
#include <cstring>
#include <iostream>
#include "LinkedList_char.h"
using namespace std;


bool IsPalindrome(linked_list list) {
	//int length = 0;
	string str = "";
	node *pt = list.first();

	while (pt != NULL) {
		str += pt->data;
		pt = pt->next;
	}

	pt = list.first();
	int len = str.length();
	for (int i = 0; i < len / 2; i++) {
		char last = str[len-1-i];
		if(last != pt->data)
			return false;
		pt = pt->next;
	}
	return true;
	
	return true;
}

int main() {
	linked_list list;
	list.add_node('a');
	list.add_node('b');
	list.add_node('c');
	list.add_node('e');
	list.add_node('c');
	list.add_node('b');
	list.add_node('a');

	printf("%d\n", IsPalindrome(list));
}