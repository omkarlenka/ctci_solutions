// ctci_2.7_intersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int getLength(Node* head)
{
	int l = 0;
	while (head)
	{
		l++;
		head = head->next;
	}

	return l;
}

int intersectPoint(Node* head1, Node* head2)
{
	if (!head1 || !head2)
		return -1;

	int l1, l2;
	l1 = getLength(head1);
	l2 = getLength(head2);

	Node *largerList, *smallerList;

	if (l1 > l2)
	{
		largerList = head1;
		smallerList = head2;
	}
	else
	{
		largerList = head2;
		smallerList = head1;
	}

	int diff = abs(l1 - l2);

	while (diff--)
	{
		largerList = largerList->next;
	}

	while (largerList && smallerList)
	{
		if (largerList == smallerList)
			return largerList->data;

		largerList = largerList->next;
		smallerList = smallerList->next;
	}

	return -1;	
}

int main()
{
	int l;
	cout << "Enter size of first linked list: ";
	cin >> l;

	cout << "Enter elements of first linked list in reverse order: ";

	Node* head1 = NULL;
	Node* tail1 = NULL;

	for (int i = 0; i < l; i++)
	{
		int n;
		cin >> n;
		Node *temp = newNode(n);
		if (head1 == NULL)
			head1 = tail1 = temp;
		else
		{
			tail1->next = temp;
			tail1 = temp;
		}
	}

	cout << "Enter size of second linked list: ";
	cin >> l;

	cout << "Enter elements of second linked list in reverse order: ";

	Node* head2 = NULL;
	Node* tail2 = NULL;

	for (int i = 0; i < l; i++)
	{
		int n;
		cin >> n;
		Node *temp = newNode(n);
		if (head2 == NULL)
			head2 = tail2 = temp;
		else
		{
			tail2->next = temp;
			tail2 = temp;
		}
	}

	cout << intersectPoint(head1, head2);

	//printLinkedList(result);
}
