#include <iostream>
using namespace std;

class binaryTree {
	struct node {
		node* left, * right;
		int data;
	};
	//node* root;
	node* newNode(int num) {
		node *newPtr = new node;
		newPtr->data = num;
		newPtr->left = newPtr->right = nullptr;
		return newPtr;
	}
	void createNodeUtil(node*& root, int num) {
		if (root == NULL) {
			root = newNode(num);
			return;
		}
		else if (num > root->data)
			createNodeUtil(root->right, num);
		else if (num < root->data)
			createNodeUtil(root->left, num);
		else
			cout << "Duplicate Value " << endl;
	}
public:
	node* root;
	binaryTree() {
		root = nullptr;
	}
	void createNode(int num) {
		createNodeUtil(root, num);
	}
	void printInorder(node *root) {
		if (root == NULL)
			return;
		printInorder(root->left);
		cout << root->data;
		printInorder(root->right);
	}
	void printPreorder(node* root) {
		if (root == NULL)
			return;
		cout << root->data;
		printPreorder(root->left);
		printPreorder(root->right);
	}
	void search(node *b,int a) {
		if (b == NULL) {
			cout << "NO";
			return;
		}
		if (a == b->data) {
			cout << "Found";
			return;
		}
		else if (a < b->data)
			search(b->left, a);
		else
			search(b->right, a);
	}
	void Del(node*& a, int num) {
		node* temp;
		if (!a->left) {
			temp = a;
			a = a->right;
			delete temp;
		}
		else if (!a->right) {
			temp = a;
			a = a->left;
			delete temp;
		}
		else {
			temp = a->right;
			while (temp->left != NULL)
				temp = temp->left;
			temp = a->left;
			temp = a;
			a = a->right;
			delete temp;
		}
	}
	void deletes(node*& b, int a) {
		if (b == NULL) {
			cout << "Not";
			return;
		}
		if (a == b->data) {
			Del(b, a);
		}
		else if (a < b->data)
			deletes(b->left, a);
		else
			deletes(b->right, a);
	}
};

int main()
{
	binaryTree a;
	a.createNode(1);
	a.createNode(2);
	a.createNode(0);
	a.createNode(3);
	//a.printInorder(a.root);
	a.deletes(a.root, 2);
	a.printInorder(a.root);
}