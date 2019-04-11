// ctci_2.5_add_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

Node* addNodes(Node* n1, Node* n2, int carry)
{
	Node *temp = newNode(0);
	if (n1 == NULL)
		temp->data = carry + (n2->data);
	else if(n2 == NULL)
		temp->data = carry + (n1->data);
	else
	{
		temp->data = carry + n1->data + n2->data;
	}

	return temp;
}

Node*  addTwoLists(Node* first, Node* second) 
{
	int carry = 0;
	Node *result = NULL;
	Node *tail = NULL;

	while (first && second)
	{
		Node* n = addNodes(first, second, carry);
		carry = (n->data)/10;
		n->data = (n->data) % 10;

		if (result == NULL)
			result = tail = n;
		else
		{
			tail->next = n;
			tail = n;
		}

		first = first->next;
		second = second->next;
	}

	while (first)
	{
		Node *n = addNodes(first, NULL, carry);
		carry = (n->data) / 10;
		n->data = (n->data) % 10;
		tail->next = n;
		tail = n;

		first = first->next;
	}

	while (second)
	{
		Node *n = addNodes(NULL, second, carry);
		carry = (n->data) / 10;
		n->data = (n->data) % 10;
		tail->next = n;
		tail = n;

		second = second->next;
	}

	if (carry != 0)
		tail->next = newNode(carry);

	return result;

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
		Node *temp  = newNode(n);
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

	Node *result = addTwoLists(head1, head2);

	printLinkedList(result);
}
