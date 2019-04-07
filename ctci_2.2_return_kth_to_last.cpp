// ctci_2.2_return_kth_to_last.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int getNthFromLast(Node *head, int n)
{
	if (head == NULL)
		return -1;

	Node *p1, *p2;

	p1 = p2 = head;

	while (p2 && n--)
	{
		p2 = p2->next;
	}

	if (p2 == NULL && n!=0)
		return -1;

	while (p2 != NULL)
	{
		p2 = p2->next;
		p1 = p1->next;
	}

	return p1->data;
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
	cout << "Enter k:";
	cin >> k;

	cout << getNthFromLast(head, k);

	//printLinkedList(head);
}
