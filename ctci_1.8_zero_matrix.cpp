// ctci_1.8_zero_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void printMatrix(int **M, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << M[i][j] << " ";
		}

		cout << endl;
	}
}

void setFirstRowCol(int **M, int m, int n)
{
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (M[i][j] == 0)
			{
				M[0][j] = M[i][0] = 0;
			}
		}
	}
}

void nullifyRowCol(int **M, int m, int n)
{
	//nullify row

	for (int i = 1;i < m; i++)
	{
		if (M[i][0] == 0)
		{
			for (int j = 1; j < n; j++)
				M[i][j] = 0;
		}
	}

	//nullify col

	for (int j = 1; j < n; j++)
	{
		if (M[0][j] == 0)
		{
			for (int i = 1; i < m; i++)
				M[i][j] = 0;
		}
	}
}

void nullifyMatrix(int **M, int m, int n)
{
	bool first_row_zero = false;
	bool first_col_zero = false;

	for (int j = 0; j < n; j++)
	{
		if (M[0][j] == 0)
			first_row_zero = true;
	}

	for (int i = 0; i < m; i++)
	{
		if (M[i][0] == 0)
			first_col_zero = true;
	}

	setFirstRowCol(M, m, n);

	printMatrix(M, m, n);

	nullifyRowCol(M, m, n);

	printMatrix(M, m, n);

	if (first_row_zero)
	{
		for (int j = 0; j < n; j++)
			M[0][j] = 0;
	}

	if (first_col_zero)
	{
		for (int i = 0; i < m; i++)
			M[i][0] = 0;
	}

}

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int m,n;
		cin >> m >> n;
		int **M = new int*[m];
		for (int i = 0; i < m; i++)
		{
			M[i] = new int[n];
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> M[i][j];
			}
		}

		nullifyMatrix(M, m, n);

		printMatrix(M, m, n);

		//free memory
		for (int i = 0; i < m ;i++)
			delete[] M[i];

		delete[] M;
	}

}