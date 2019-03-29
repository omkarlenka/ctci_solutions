#include <iostream>
#include <vector>

using namespace std;

void printSquareMatrix(int **M, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << M[i][j] << " ";
		}
	}

	cout << endl;

}

vector<int> getNextPosition(int i, int j, int n)
{
	vector<int> position;

	if (i == 0)
	{
		position.push_back((n - 1) - j);
		position.push_back(0);
	}
	else if (i == n - 1)
	{
		position.push_back((n - 1) - j);
		position.push_back(n-1);
	}
	else if (j == 0)
	{
		position.push_back(n-1);
		position.push_back(i);
	}
	else if (j == n - 1)
	{
		position.push_back(0);
		position.push_back(i);
	}
	return position;
}

void rotateNow(int **M, int i, int j, int n)
{
	int count = 0;
	int layer = i;
	int temp = M[i][j];
	while (count < 4)
	{
		vector<int> position = getNextPosition((i-layer), (j-layer), n);

		int next_i = position[0]+layer;
		int next_j = position[1]+layer;

		int temp1 = M[next_i][next_j];
		M[next_i][next_j] = temp;
		temp = temp1;

		i = next_i;
		j = next_j;

		count++;
	}
}

void rotateLayer(int** M, int n, int layer)
{
	for(int j = layer;j<n-1+layer;j++)
		rotateNow(M, layer, j, n);
}

void rotateSquareMatrix(int** M, int n)
{
	int layer = 0;
	while (n > 1)
	{
		rotateLayer(M, n, layer);
		n -= 2;
		layer++;
	}
}

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		int **M = new int*[n];
		for (int i = 0; i < n; i++)
		{
			M[i] = new int[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> M[i][j];
			}
		}

		rotateSquareMatrix(M, n);

		printSquareMatrix(M, n);

		//free memory
		for (int i = 0; i < n; i++)
			delete[] M[i];

		delete[] M;
	}

}