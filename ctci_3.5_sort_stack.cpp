// ctci_3.5_sort_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void insertInS2(int t, stack<int> &s1, stack<int> &s2)
{
	int actual_size = s1.size();

	int top_s2 = s2.top();
	while (t > s2.top())
	{
		s2.pop();
		s1.push(top_s2);

		if (!s2.empty())
			top_s2 = s2.top();
		else
			break;
	}

	s2.push(t);
	 
	while (s1.size() != actual_size)
	{
		s2.push(s1.top());
		s1.pop();
	}
}

void SortedStack::sort()
{
	stack<int> s2;

	s2.push(s.top());
	s.pop();

	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		insertInS2(t, s, s2);
	}

	while (!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
}

void printStack(stack<int> s)
{
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		SortedStack sortedstack;
		int n;
		cin >> n;
		while (n--)
		{
			int i;
			cin >> i;
			sortedstack.s.push(i);
		}
		sortedstack.sort();

		printStack(sortedstack.s);
	}
}
