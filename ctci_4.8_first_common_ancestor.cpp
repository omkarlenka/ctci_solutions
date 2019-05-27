// ctci_4.8_first_common_ancestor.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void find(Node* root, int n1, int n2, bool &n1_found, bool &n2_found)
{
	if (root == NULL)
		return;

	if (root->data == n1)
		n1_found = true;
	else if (root->data == n2)
		n2_found = true;

	if (n1_found && n2_found)
		return;

	find(root->left, n1, n2, n1_found, n2_found);
	find(root->right, n1, n2, n1_found, n2_found);
}

Node* LCA(Node* root, int n1, int n2)
{
	if (root == NULL)
		return root;

	if (root->data == n1 || root->data == n2)
		return root;

	Node* leaft_lca = LCA(root->left, n1, n2);
	Node* right_lca = LCA(root->right, n1, n2);

	Node* lca_node;

	if (leaft_lca && right_lca)
		lca_node = root;
	else if (leaft_lca)
		lca_node = leaft_lca;
	else
		lca_node = right_lca;

	return lca_node;
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	root->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	Node* n = LCA(root, 6, 7);

	if (n)
		cout << n->data;
	else
		cout << "NULL";
}
