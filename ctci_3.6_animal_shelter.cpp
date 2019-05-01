// ctci_3.6_animal_shelter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class DogQueue
{
private:
	queue<string> dog_queue;
public:
	DogQueue() {}
	void enqueue(string animalname)
	{
		this->dog_queue.push(animalname);
	}
	string dequeue()
	{
		string res = this->dog_queue.front();
		this->dog_queue.pop();
		return res;
	}
};

class CatQueue
{
private:
	queue<string> cat_queue;
public:
	CatQueue() {}
	void enqueue(string animalname)
	{
		this->cat_queue.push(animalname);
	}
	string dequeue()
	{
		string res = this->cat_queue.front();
		this->cat_queue.pop();
		return res;
	}
};

class AnimalQueue
{
	DogQueue* dog_queue;
	CatQueue* cat_queue;
	queue<string> enqueue_order;
public:
	AnimalQueue()
	{
		this->dog_queue = new DogQueue();
		this->cat_queue = new CatQueue();
	}

	string dequeueAny()
	{
		string res;
		if (this->enqueue_order.front() == "cat")
			res = this->cat_queue->dequeue();
		else if (this->enqueue_order.front() == "dog")
			res = this->dog_queue->dequeue();

		enqueue_order.pop();

		return res;
	}

	void enqueue(string animaltype, string animalname)
	{
		if (animaltype == "cat")
		{
			cat_queue->enqueue(animalname);
			this->enqueue_order.push("cat");
		}
		else if (animaltype == "dog")
		{
			dog_queue->enqueue(animalname);
			this->enqueue_order.push("dog");
		}
		else
			cout << "Invalid Animal type";
	}

	string dequeDog()
	{
		return dog_queue->dequeue();
	}
	string dequeCat()
	{
		return cat_queue->dequeue();
	}
};

int main()
{
	int option;
	AnimalQueue animalqueue;
	do {
		cout << "1. enqueue " << endl;
		cout << "2. dequeueAny " << endl;
		cout << "3. dequeueDog " << endl;
		cout << "4. dequeueCat " << endl;

		cin >> option;

		switch (option)
		{
			case 1:
				{
					string animalname = "";
					string animaltype;

					cout << "Enter animaltype(cat/dog):" << endl;
					cin >> animaltype;
					cout << "Enter animalname:" << endl;
					cin >> animalname;

					animalqueue.enqueue(animaltype, animalname);
				}
				break;
			case 2:
				{
					cout << animalqueue.dequeueAny() << endl;
				}
				break;
			case 3:
				{
					cout << animalqueue.dequeDog() << endl;
				}
				break;
			case 4:
				{
					cout << animalqueue.dequeCat() << endl;
				}
				break;
		}

	} while (1);

}
