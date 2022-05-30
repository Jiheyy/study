#include <iostream>
using namespace std;

typedef struct node {
	int data;
	node *left, *right;
}node;

class BinaryTree {
private:
	node *root;
public:
	BinaryTree() {
		root = NULL;
		//cout << "생성자";
	}

	node* insertLeft(node* parent, int value) {
		//cout << parent <<endl;
		//cout << value<<endl;
		node *tmp = new node;

		tmp->data = value;
		tmp->left = NULL;
		tmp->right = NULL;

		if(root == NULL) {
			root = tmp;
			cout << "root :" << root->data <<endl;
		}
		else {
			cout << parent->data <<"s right :" << tmp->data<<endl;
			parent->left = tmp;
		}

		return tmp;
	}

	node* insertRight(node *parent, int value) {
		node *tmp = new node;
		tmp->data = value;
		if(root == NULL){
			cout << "root :" << root <<endl;
			root = tmp;
		}
		else {
			cout << parent->data <<"s right :" << tmp->data <<endl;
			parent->right = tmp;
		}

		return tmp;
	}

	node * Root() {

		return root;
	}
};