// ctci_4.6_successor.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>

using namespace std;

int flag = 0;

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

Node* inOrderSuccessorUtil(Node* root, Node* n, Node* succ)
{
	if (root == NULL)
		return root;

	if (root == n)
		return succ;
	else if (root->data > n->data)
	{
		succ = root;
		return inOrderSuccessorUtil(root->left, n, succ);
	}
	else
		return inOrderSuccessorUtil(root->right, n, succ);
}

Node* inOrderSuccessor(Node* root, Node* n)
{
	Node* succ = NULL;

	if (n->right)
	{
		succ = n->right;
		while (succ->left)
			succ = succ->left;
	}
	else
		succ = inOrderSuccessorUtil(root, n, succ);

	return succ;
}

int main()
{
	Node *root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	//root->right->left = newNode(11);
	//root->right->right = newNode(20);

	Node* n = inOrderSuccessor(root, root->left->right->right);
	
	if (n == NULL)
		cout << -1;
	else
		cout << n->data;
}

