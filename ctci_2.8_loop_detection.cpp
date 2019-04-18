// ctci_2.8_loop_detection.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int detectloop(Node* head)
{
	int result = 0;
	if (head == NULL)
		return result;

	Node *p1, *p2;
	p1 = p2 = head;

	while (p1 && p2)
	{
		p1 = p1->next;

		if (p2->next)
			p2 = p2->next->next;
		else
			p2 = p2->next;

		if (p1 == p2)
		{
			result = 1;
			break;
		}
	}

	return result;
}

void removeTheLoop(Node *head)
{
	if (!detectloop(head))
		return;

	Node *p1, *p2, *p2_prev;

	p1 = head->next;
	p2 = head->next->next;
	p2_prev = head->next;

	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next->next;
		p2_prev = p2_prev->next->next;
	}

	p1 = head;

	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
		p2_prev = p2_prev->next;
	}

	p2_prev->next = NULL;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int l;
		cout << "Enter size of linked list: ";
		cin >> l;

		cout << "Enter elements of linked list order: ";

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

		cout << "Enter the nth node that is pointed by last node:";
		int x;
		cin >> x;

		Node* temp = head1;

		while (x>1)
		{
			temp = temp->next;
			x--;
		}

		tail1->next = temp;

		removeTheLoop(head1);
		//printLinkedList(head1);
	}

	
}
