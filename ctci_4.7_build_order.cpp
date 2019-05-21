// ctci_4.7_build_order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topoSortUtil(int u, vector<int> adj[], bool* &visited, stack<int> &s)
{
	vector<int>::iterator itr;

	for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
	{
		if (!visited[*itr])
		{
			topoSortUtil(*itr, adj, visited, s);
			visited[*itr] = true;
		}
	}

	s.push(u);
	visited[u] = true;
}

int* topoSort(int V, vector<int> adj[])
{
	/*
	for (int i = 0; i < V; i++)
	{
		cout << i << endl;

		vector<int>::iterator itr;
		for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
		{
			cout << *itr << " ";
		}
		cout << endl;
	}
	*/

	bool *visited = new bool[V];
	stack<int> s;

	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			topoSortUtil(i, adj, visited, s);
		}
	}

	int* res = new int[V];
	int i = 0;

	while (!s.empty())
	{
		int t = s.top();
		s.pop();
		res[i++] = t;
	}

	return res;
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int E, N;
		cin >> E >> N;

		vector<int> *adj = new vector<int>[N];  //array of vectors

		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;

			adj[u].push_back(v);
		}

		/*
		for (int i = 0; i < N; i++)
		{
			cout << i << endl;

			vector<int>::iterator itr;
			for (itr = adj[i].begin(); itr != adj[i].end(); itr++)
			{
				cout << *itr << " ";
			}
			cout << endl;
		}
		*/

		int* res = topoSort(N, adj);

		for (int i = 0; i < N; i++)
			cout << res[i] << " ";

		cout << endl;
	}
}
