// ctci_3.2_stack_min.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

class StackMin
{
private:
	struct StackNode
	{
		int data;
		int min;
	};

	int maxSize;
	stack<StackNode> stackmin;

public:

	StackMin(int maxSize)
	{
		this->maxSize = maxSize;
	}

	void push(int a)
	{
		if (this->isFull(a))
			return;

		int min;
		if (stackmin.empty())
		{
			min = a;
		}
		else
		{	
			StackNode t = stackmin.top();
			min = t.min;
			if (a < t.min)
				min = a;
		}

		stackmin.push(StackNode{ a,min });
	}

	bool isFull(int n)
	{
		if (stackmin.size() == this->maxSize)
			return true;

		return false;
	}

	bool isEmpty()
	{
		return stackmin.empty();
	}

	int pop()
	{
		StackNode t = stackmin.top();
		stackmin.pop();

		return t.data;
	}
	int getMin()
	{
		StackNode t = stackmin.top();
		return t.min;
	}
};

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int n;
		cout << "Enter no. of elements in stack:";
		cin >> n;
		StackMin stackmin(n);

		cout << "Enter elements of stack:";

		while (n--)
		{
			int temp;
			cin >> temp;

			stackmin.push(temp);
		}

		cout << stackmin.getMin();
	}
}
