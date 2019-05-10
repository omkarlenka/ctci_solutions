// ctci_4.3_depth_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <list>

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

void createListUtil(Node* root, vector<list<int>> &v, int level)
{
	if (root == NULL)
		return;

	//if ((level) > (v.size() - 1))
	int a = level;
	int b = (v.size() - 1);
	if(a > b)
	{
		list<int> l;
		v.push_back(l);
	}
	v[level].push_back(root->data);
	createListUtil(root->left, v, level+1);
	createListUtil(root->right, v, level + 1);
}

void createList(Node* root)
{
	vector<list<int>> v;

	createListUtil(root, v, 0);

	for (int i = 0; i < v.size(); i++)
	{
		list<int>::iterator it;
		for (it = v[i].begin();it!=v[i].end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
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

	createList(root);
}
