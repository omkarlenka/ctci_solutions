// ctci_3.4_queue_via_stacks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class StackQueue {
private:
	// These are STL stacks ( http://goo.gl/LxlRZQ )
	stack<int> s1;
	stack<int> s2;
	void shiftElements();
public:
	void push(int);
	int pop();
};

void StackQueue::shiftElements()
{
	while (!s1.empty())
	{
		int t = s1.top();
		s1.pop();
		s2.push(t);
	}
}

void StackQueue::push(int x)
{
	s1.push(x);
}

int StackQueue::pop()
{
	int res = -1;
	if (s2.empty())
	{
		shiftElements();
	}
	if (!s2.empty())
	{
		res = s2.top();
		s2.pop();
	}

	return res;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int Q;
		cin >> Q;
		StackQueue stackqueue;

		while (Q--)
		{
			int i;
			cin >> i;
			if (i == 1)
			{
				int j;
				cin >> j;
				stackqueue.push(j);
			}
			else if(i == 2)
			{
				cout << stackqueue.pop() << " ";
			}
		}
		cout << endl;
	}
}
