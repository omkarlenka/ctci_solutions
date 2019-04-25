// ctci_3.3_stack_of_plates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks
{
private:
	int max_size;
	vector<stack<int>> setofstack;

	int getBottomElement(stack<int> &s1)
	{
		stack<int> s2;

		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		int n = s2.top();
		s2.pop();

		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}

		return n;
	}
public:
	SetOfStacks(int max_size)
	{
		this->max_size = max_size;
	}

	void push(int n)
	{
		if (setofstack.size() == 0 || setofstack.back().size() == this->max_size)
		{
			stack<int> s;
			s.push(n);
			setofstack.push_back(s);
		}
		else
		{
			setofstack.back().push(n);
		}
	}

	void pop()
	{
		setofstack.back().pop();

		if (setofstack.back().empty())
			setofstack.pop_back();
	}

	int top()
	{
		return setofstack.back().top();
	}

	int topAt(int index)
	{
		return setofstack[index].top();
	}

	void popAt(int index)
	{
		setofstack[index].pop();

		for (int i = index + 1; i < setofstack.size(); i++)
		{
			int n = getBottomElement(setofstack[i]);
			setofstack[i - 1].push(n);
		}
	}
};

int main()
{
	cout << "Enter max size of each stack:";
	int l;
	cin >> l;

	SetOfStacks s(l);

	do 
	{
		cout << "1. push" << endl << "2. pop" << endl << "3.popAt" << endl << "4.top" << endl << "5.topAt" << endl;
		int n;
		cin >> n;

		switch (n)
		{
		case 1:
			cout << "Enter element to push:";
			int d;
			cin >> d;

			s.push(d);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			cout << "Enter index for popAt: ";
			int i;
			cin >> i;

			s.popAt(i);
			break;
		case 4:
			cout << "top = " << s.top() << endl;
			break;
		case 5:
			cout << "Enter index for topAt:";
			int j;
			cin >> j;
			cout << "topAt[" << j << "] = " << s.topAt(j) << endl;
			break;
		}

	} while (1);
}



