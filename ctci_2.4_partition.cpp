// ctci_2.4_partition.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

Node* partition(Node* head, int k)
{
	Node* smallerStart = NULL;
	Node* smallerEnd = NULL;
	Node* greaterStart = NULL;
	Node* greaterEnd = NULL;

	while (head)
	{
		Node **start, **end;
		if (head->data < k)
		{
			start = &smallerStart;
			end = &smallerEnd;
		}
		else
		{
			start = &greaterStart;
			end = &greaterEnd;
		}
		
		if (*start == NULL)
			*start = *end = head;
		else
		{
			(*end)->next = head;
			(*end) = (*end)->next;
		}

		head = head->next;
	}

	if (smallerStart != NULL)
	{
		greaterEnd->next = NULL;
		smallerEnd->next = greaterStart;
		head = smallerStart;
	}
	else
		head = greaterStart;

	return head;
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
	cout << "Enter pivot element:";
	cin >> k;

	head = partition(head, k);

	printLinkedList(head);
}

