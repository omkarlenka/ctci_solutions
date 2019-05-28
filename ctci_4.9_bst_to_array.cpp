// ctci_4.9_bst_to_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void weave_lists_util(list<int> l1, list<int> l2, list<int> &prefix, vector<list<int>> &result)
{
	if(l1.empty() || l2.empty())
	{
		list<int> l;

		if(l1.empty())
			l = l2;
		else
			l = l1;

		list<int> prefix_copy = prefix;

		prefix_copy.splice(prefix_copy.end(), l);
		result.push_back(prefix_copy);
		return;				
	}

	if(!l1.empty())
	{
		int head = l1.front();
		l1.pop_front();
		prefix.push_back(head);
		weave_lists_util(l1, l2, prefix, result);
		prefix.pop_back();
		l1.push_front(head);
	}

	if(!l2.empty())
	{
		int head = l2.front();
		l2.pop_front();
		prefix.push_back(head);
		weave_lists_util(l1, l2, prefix, result);
		prefix.pop_back();
		l2.push_front(head);
	}
}

vector<list<int>> weave_lists(list<int> l1, list<int> l2)
{
	list<int> prefix;
	vector<list<int>> result;
	weave_lists_util(l1, l2, prefix, result);

	return result;
}

vector<list<int>> allSequences(Node* root)
{
	vector<list<int>> result;
	if (root == NULL)
	{
		list<int> l;
		result.push_back(l);
		return result;
	}

	list<int> prefix;
	prefix.push_back(root->data);

	vector<list<int>> left_seq = allSequences(root->left);
	vector<list<int>> right_seq = allSequences(root->right);

	vector<list<int>>::iterator left_itr;
	
	if (!left_seq[0].empty() && !right_seq[0].empty()) //both left and right sequence are not  empty
	{
		for (left_itr = left_seq.begin(); left_itr != left_seq.end(); left_itr++)
		{
			vector<list<int>>::iterator right_itr;
			vector<list<int>> weaved_lists;
			for (right_itr = right_seq.begin(); right_itr != right_seq.end(); right_itr++)
			{
				weaved_lists = weave_lists(*left_itr, *right_itr);
				for (int i = 0; i < weaved_lists.size(); i++)
				{
					prefix.splice(prefix.end(), weaved_lists[i]);
					result.push_back(prefix);
					prefix.clear();
					prefix.push_back(root->data);
				}
			}
		}
	}
	else if (!left_seq[0].empty())	//right sequence is empty
	{
		vector<list<int>>::iterator itr;
		for (itr = left_seq.begin(); itr != left_seq.end(); itr++)
		{
			prefix.splice(prefix.end(), *itr);
			result.push_back(prefix);
			prefix.clear();
			prefix.push_back(root->data);
		}
	}
	else if (!right_seq[0].empty())	//left sequence is empty
	{
		vector<list<int>>::iterator itr;
		for (itr = right_seq.begin(); itr != right_seq.end(); itr++)
		{
			prefix.splice(prefix.end(), *itr);
			result.push_back(prefix);
			prefix.clear();
			prefix.push_back(root->data);
		}
	}
	else
		result.push_back(prefix);

	return result;
}

int main()
{
	Node *root = newNode(5);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->right = newNode(10);
	root->right->left = newNode(7);
	root->right->right = newNode(15);

	vector<list<int>> result= allSequences(root);

	vector<list<int>>::iterator itr;

	for (itr = result.begin(); itr != result.end(); itr++)
	{
		list<int>::iterator list_itr;

		for (list_itr = (*itr).begin(); list_itr != (*itr).end(); list_itr++)
		{
			cout << *list_itr << " ";
		}

		cout << endl;

	}

}

/* This is UT for weave_list
void unittest_weave_list()
{
	list<int> l1;
	list<int> l2;

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	l2.push_back(4);
	l2.push_back(5);
	l2.push_back(6);

	vector<list<int>> result = weave_lists(l1, l2);

	vector<list<int>>::iterator itr;

	for(itr = result.begin();itr!=result.end();itr++)
	{
		list<int>::iterator list_itr;

		for(list_itr=(*itr).begin();list_itr!=(*itr).end();list_itr++)
		{
			cout << *list_itr << " ";			
		}

		cout << endl;

	}

}
*/

