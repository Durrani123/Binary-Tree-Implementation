#include <iostream>
using namespace std;

class Bt {
	struct node {
		int data;
		node* left, * right;
	};
	node* createNewNode(int data) {
		node* a = new node;
		a->data = data;
		a->left = NULL;
		a->right = NULL;
		return a;
	}

	void add_util(node*& b, int a) {
		if (!b) {
			b = createNewNode(a);
			return;
		}
		else if (a > b->data)
			add_util(b->right, a);
		else if (a < b->data)
			add_util(b->left, a);
		else
			cout << "Duplicate value " << endl;
	}
	void makeDeletion(node*& a) {
		node* temp;
		if (!a->left) {
			temp = a;
			a = (a)->right;
			delete temp;
		}
		else if (!a->right) {
			temp = a;
			a = (a)->left;
			delete temp;
		}
		else {
			temp = a->right;
			while (temp->left)
				temp = temp->left;
			temp = a->left;
			temp = a;
			a = a->right;
			delete temp;
		}
	}
	void deleteUtil(node*& b, int a) {
		if (b == NULL) {
			cout << "Wrong";
				return;
		}	
		else if (a > b->data )
			deleteUtil(b->right, a);
		else if (a < b->data)
			deleteUtil(b->left, a);
		else
			makeDeletion(b);
	}
public:
	node* root;
	Bt() {
		root = NULL;
	}
	void add(int num) {
		add_util(root,num);
	}
	void Delete(int num) {
		deleteUtil(root, num);
	}
};

int main()
{
	Bt a;
	a.add(1);
	a.add(0);
	a.add(3);
	a.Delete(4);
	//cout << a.root->data;
}