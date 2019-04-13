// ctci_2.6_palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

Node* isPalindromeRecursive(Node* head, int length)
{
	if (length == 2)
	{
		if (head->data == head->next->data)
			return head->next->next;
		else
			return NULL;
	}
	else if (length == 1)
	{
		return head->next;
	}


	Node* res = isPalindromeRecursive(head->next, length - 2);
	if (res && head->data == res->data)
	{
		if (res->next)
			return res->next;
		else
			return res;
	}
	else
		return NULL;
}

bool isPalindrome(Node* head)
{
	if (head == NULL || head->next == NULL)
		return true;

	int length = 0;
	Node* n = head;

	while (n)
	{
		length++;
		n = n->next;
	}
	
	if (length == 2)
	{
		if (head->data == head->next->data)
			return true;
		else
			return false;
	}

	Node* res = isPalindromeRecursive(head, length);

	return (res != NULL);
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

		cout << isPalindrome(head1) << endl;
	}

	//printLinkedList(result);
}
