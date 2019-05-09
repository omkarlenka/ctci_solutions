// ctci_4.2_minimal_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class Node 
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void printPreOrder(Node *root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

Node* arrayToBstUtil(vector<int> v, int start, int end)
{
	if (start > end)
		return NULL;
	int size = (end - start) + 1;
	int root_index;
	if (size % 2)
		root_index = start + (size / 2);
	else
		root_index = start + (size / 2) - 1;

	Node* root = new Node(v[root_index]);
	root->left = arrayToBstUtil(v, start, (root_index-1));
	root->right = arrayToBstUtil(v, (root_index + 1), end);

	return root;
}

Node* arrayToBst(vector<int> v)
{
	return arrayToBstUtil(v, 0, v.size() - 1);
}

int main() 
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i];

		printPreOrder(arrayToBst(v));

		cout << endl;
	}	

	return 0;
}
