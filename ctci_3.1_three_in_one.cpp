// ctci_3.1_three_in_one.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

class KinOneStack
{
private:
	int no_of_stack;
	int size_of_stack;
	int *values;
	int *current_size;

public:
	KinOneStack(int no_of_stack, int size_of_stack)
	{
		this->no_of_stack = no_of_stack;
		this->size_of_stack = size_of_stack;
		this->values = new int[no_of_stack*size_of_stack];
		this->current_size = new int[no_of_stack];

		memset(this->values, 0, sizeof(int)*no_of_stack*size_of_stack);
		memset(this->current_size, 0, sizeof(int)*no_of_stack);
	}

	void push(int stack_no, int value)
	{
		if (this->current_size[stack_no] == size_of_stack)
			throw "StackFull";

		this->values[getIndexOfTop(stack_no)+1] = value;
		this->current_size[stack_no]++;
	}

	void pop(int stack_no)
	{
		if(isEmpty(stack_no))
			throw "StackEmpty";

		this->current_size[stack_no] -= 1;
	}

	int getTop(int stack_no)
	{
		if (isEmpty(stack_no))
			throw "StackEmpty";

		return (this->values[getIndexOfTop(stack_no)]);
	}

	bool isEmpty(int stack_no)
	{
		return (this->current_size[stack_no] == 0);
	}

	int getIndexOfTop(int stack_no)
	{
		int index_top = (stack_no * (this->size_of_stack) + (this->current_size[stack_no])) - 1;
		return index_top;
	}
};

int main()
{
	int size_of_stack;
	cout << "Enter Size of each stack:";
	cin >> size_of_stack;

	int no_of_stacks;
	cout << "Enter no. of stacks:";
	cin >> no_of_stacks;

	KinOneStack stack(3, 5);

	stack.push(0, 1);
	stack.push(0, 2);
	stack.push(1, 3);
	stack.push(1, 4);
	stack.push(2, 5);
	stack.push(2, 6);

	try
	{

		cout << stack.getTop(0) << endl;
		cout << stack.getTop(1) << endl;
		cout << stack.getTop(2) << endl;

		stack.pop(0);
		stack.pop(1);
		stack.pop(2);

		cout << stack.getTop(0) << endl;
		cout << stack.getTop(1) << endl;
		cout << stack.getTop(2) << endl;

		stack.pop(0);
		stack.pop(1);
		stack.pop(2);

		stack.push(0, 1);
		stack.push(0, 2);
		stack.push(0, 3);
		stack.push(0, 4);
		stack.push(0, 5);
		stack.push(0, 6);

		cout << stack.getTop(0) << endl;
		cout << stack.getTop(1) << endl;
		cout << stack.getTop(2) << endl;
	}
	catch(...)
	{
		cout << "Exiting with Exception" << endl;
	}
	
	return 0;    
}
