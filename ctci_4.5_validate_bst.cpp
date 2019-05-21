// ctci_4.5_validate_bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} Node;

Node* newNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;

	return n;
}

bool isBSTUtils(Node* root, int min_val, int max_val)
{
	if (root == NULL)
		return true;

	if (root->data > max_val || root->data < min_val)
		return false;
	else
		return ((isBSTUtils(root->left, min_val, (root->data) - 1)) && (isBSTUtils(root->right, (root->data) + 1, max_val)));
}

bool isBST(Node* root)
{
	return isBSTUtils(root, INT_MIN, INT_MAX);
}

int main()
{
	Node *root = newNode(10);
	root->left = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(7);
	root->right = newNode(15);
	root->right->left = newNode(11);
	root->right->right = newNode(20);

	cout << isBST(root);
}

