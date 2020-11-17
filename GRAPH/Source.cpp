#include<iostream>
#include<iomanip>
#include<vector>
#include<list>

int** MatrixAdjacent(int vertex, int edge)
{
	
	int head;
	int tail;
	int** arr = new int* [vertex];
	for (int i = 0; i < vertex; ++i)
	{
		arr[i] = new int[vertex] {0};
	}

	for (int i = 0; i < edge; ++i)
	{
		std::cin >> head >> tail;
		arr[head - 1][tail - 1] = 1;
		arr[tail - 1][head - 1] = 1;
	}

	return arr;
}

void PrintMatrixAdjacent(int** arr, int vertex, int edge)
{
	std::cout << " ";
	for (int i = 0; i < vertex; ++i)
	{
		std::cout << std::setw(3) << i + 1;
	}
	
	for (int i = 0; i < vertex; ++i)
	{
		std::cout << '\n' << i + 1;
		for (int j = 0; j < vertex; ++j)
		{
			std::cout << std::setw(3) << arr[i][j];
		}
	}
}

int main()
{
	int vertex;
	int edge;
	std::cout << "Number of vertex : ";
	std::cin >> vertex;
	std::cout << "Number of edge : ";
	std::cin >> edge;

	int** matrix = MatrixAdjacent(vertex, edge);
	PrintMatrixAdjacent(matrix, vertex, edge);

	for (int i = 0; i < vertex; ++i)
	{
		delete[] matrix[i];
	}
	delete matrix;
	return 0;
}