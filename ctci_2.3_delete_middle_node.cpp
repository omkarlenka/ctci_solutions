// ctci_2.3_delete_middle_node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* newNode(int data)
{
	Node* n = new Node;
	n->data = data;
	n->next = NULL;

	return n;
}

void printLinkedList(Node* head)
{
	Node* n = head;

	while (n != NULL)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void deleteNode(Node *node)
{
	Node* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;

	delete temp;
}

int main()
{
	int l;
	cout << "Enter size of linked list: ";
	cin >> l;

	cout << "Enter elements of linked list: ";

	Node* head = NULL;
	Node *lastNode = head;

	for (int i = 0; i < l; i++)
	{
		int n;
		cin >> n;

		if (head == NULL)
		{
			head = newNode(n);
			lastNode = head;
		}
		else
		{
			lastNode->next = newNode(n);
			lastNode = lastNode->next;
		}
	}

	int k;
	cout << "Enter node data to be deleted:";
	cin >> k;

	Node* n = head;

	while (n->data != k)
	{
		n = n->next;
	}

	deleteNode(n);

	printLinkedList(head);
}

