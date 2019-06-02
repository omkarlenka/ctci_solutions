// ctci_4.10_check_subtree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool isSimilar(Node* n1, Node* n2)
{
	if (n1 == NULL && n2 == NULL)
		return 1;
	else if (n1 == NULL || n2 == NULL)
		return 0;

    if(n1->data != n2->data)
        return 0;
    else
        return (isSimilar(n1->left, n2->left) && isSimilar(n1->right, n2->right));
}

bool isSubtree(Node*  T1 ,Node * T2)
{
    if(T1 == NULL || T2 == NULL)
        return 0;

    if(T1->data == T2->data)
    {
        if(isSimilar(T1, T2))
            return 1;
    }

    if(isSubtree(T1, T2->left))
        return 1;

    return isSubtree(T1, T2->right);
}

int main()
{
	Node *root1 = newNode(10);
	root1->left = newNode(20);
	root1->left->left = newNode(40);
	root1->left->right = newNode(60);
	root1->right = newNode(30);
	//root1->right->right = newNode(100);
	
    Node *root2 = newNode(26);
    root2->right = newNode(10);
	root2->right->left = newNode(20);
	root2->right->left->left = newNode(40);
	root2->right->left->right = newNode(60);
	root2->right->right = newNode(30);

    cout << isSubtree(root1, root2);

}
