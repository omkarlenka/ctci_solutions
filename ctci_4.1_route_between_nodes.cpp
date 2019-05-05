// ctci_4.1_route_between_nodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<list>

using namespace std;

class Graph
{
private:
	int no_of_vertices;
	list<int> *arr;

	bool isReachableUtil(int v1, int v2, int **visited)
	{
		list<int>::iterator it;
		for (it = arr[v1].begin(); it != arr[v1].end(); it++)
		{
			if (*it == v2)
				return true;

			if (!(*visited)[*it])
			{
				(*visited)[*it] = 1;
				return isReachableUtil(*it, v2, visited);
			}
		}
	}
public:
	Graph(int no_of_vertices)
	{
		this->no_of_vertices = no_of_vertices+1;  //To accomodate arr[0], can be optimized, don't care now
		this->arr = new list<int>[this->no_of_vertices];
	}
	void addEdge(int v1, int v2)
	{
		this->arr[v1].push_back(v2);
	}

	bool isReachable(int v1, int v2)
	{
		int *visited = new int[no_of_vertices+1];
		memset(visited, 0, no_of_vertices*sizeof(int));

		return isReachableUtil(v1, v2, &visited);
	}
};

int main()
{
	Graph *g = new Graph(6);

	g->addEdge(1,2);
	g->addEdge(2, 5);
	g->addEdge(2, 3);
	g->addEdge(5, 3);
	g->addEdge(3, 7);
	g->addEdge(3, 4);

	cout << g->isReachable(1, 4) << endl;
	cout << g->isReachable(3, 1) << endl;
	cout << g->isReachable(5, 7) << endl;
	cout << g->isReachable(5, 1) << endl;
}
