// ctci_4.4_check_balanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>

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

int isBalancedUtil(Node* root)
{
	if (root == NULL)
		return 0;

	int left_height = isBalancedUtil(root->left);
	int right_height = isBalancedUtil(root->right);

	if ((left_height == -1) || (right_height == -1) || abs(left_height - right_height) > 1)
		return -1;
	else
		return max(left_height, right_height)+1;
}

bool isBalanced(Node *root)
{
	if (isBalancedUtil(root) == -1)
		return false;
	else
		return true;
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(4);
	//root->right = newNode(5);
	//root->right->left = newNode(6);
	//root->right->right = newNode(7);

	cout << isBalanced(root);
}
