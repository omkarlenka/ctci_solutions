// remove_dups.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <iterator>

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

Node* removeDuplicates(Node* head)
{
	map<int, bool> M;
	Node *curr = head;
	Node *prev = NULL;

	while (curr!= NULL)
	{
		if (M[curr->data])
		{
			prev->next = curr->next;
			delete curr;
			curr = prev;
		}
		else
		{
			M[curr->data] = true;
		}
		prev = curr;
		curr = curr ->next;
	}

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

	removeDuplicates(head);

	printLinkedList(head);
}