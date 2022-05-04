#include <iostream>

struct node {
	char data;
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

	node* add_node(int n) {
		node *temp = new node;
		temp->data = n;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}

		return temp;
	}

	node* first() {
		return head;
	}

	node* last() {
		return tail;
	}

	void printLinkedList() {
		if (head == NULL) return;

		node* currentNode = head;
		while (currentNode->next != NULL) {
			printf("%c - ", currentNode->data);
			currentNode = currentNode->next;
		}
		printf("%c", currentNode->data);

		printf("\n");
	}
};