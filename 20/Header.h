#pragma once
#include <iostream>

using namespace std;

struct tree
{
	int data;
	tree* left;
	tree* right;
};

class tree_
{
	tree* root;
	tree* insert(tree*& leaf, int element) {
		if (leaf == NULL) {
			tree* new_leaf = new tree;
			new_leaf->data = element;
			new_leaf->left = NULL;
			new_leaf->right = NULL;
			return new_leaf;
		}
		if (element < leaf->data)
			leaf->left = insert(leaf->left, element);
		if (element > leaf->data)
			leaf->right = insert(leaf->right, element);
		return leaf;
	}
	void print(tree* l)
	{
		if (l == NULL)
			return;
		cout << l->data << " ";
		print(l->left);
		print(l->right);
	}
public:
	tree_();
	~tree_() { delete root; };
	void insert(int element) {
		root = insert(root, element);
	}
	void print();
	void min();
};

tree_::tree_()
{
	root = NULL;
}

void tree_::print()
{
	print(root);
}

void tree_::min()
{
	tree* p = root;
	while (p->left != NULL)
	{
		p = p->left;
	}
	cout << endl << "Min: " << p->data << endl;
}