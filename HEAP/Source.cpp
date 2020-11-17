#include<iostream>
#include<algorithm>

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << ' ';
	}
}

void Max_Heapify(int* arr, int n, int pos)
{
	int left = pos * 2;
	int right = pos * 2 + 1;
	int largest = pos;
	if (left < n && arr[left] > arr[pos])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	if (largest != pos)
	{
		std::swap(arr[pos], arr[largest]);
		Max_Heapify(arr, n, largest);
	}
}

void Creat_Max_Heap(int* arr, int n)
{
	for (int i = n / 2; i >= 1; --i)
	{
		Max_Heapify(arr, n, i);
	}
}

void Heap_Sort_Ascending(int* arr, int n)
{
	Creat_Max_Heap(arr, n);
	while (n > 1)
	{
		std::swap(arr[1], arr[n - 1]);
		--n;
		Max_Heapify(arr, n, 1);
	}

}

void Min_Heapify(int* arr, int n, int pos)
{
	int smallest = pos;
	int left = 2 * pos;
	int right = 2 * pos + 1;
	if (left < n && arr[left] < arr[pos])
	{
		smallest = left;
	}
	if (right < n && arr[right] < arr[smallest])
	{
		smallest = right;
	}
	if (smallest != pos)
	{
		std::swap(arr[pos], arr[smallest]);
		Min_Heapify(arr, n, smallest);
	}
}

void Creat_Min_Heap(int* arr, int n)
{
	for (int i = n / 2; i >= 1; --i)
	{
		Min_Heapify(arr, n, i);
	}
}

void Heap_Sort_Descending(int* arr, int n)
{
	Creat_Min_Heap(arr, n);
	while (n > 1)
	{
		std::swap(arr[1], arr[n - 1]);
		--n;
		Min_Heapify(arr, n, 1);
	}
}

int main()
{
	int n = 8;
	int* arr = new int[n]{ -1, 45, 12, 67, 48, 9, 1, 6 };
	Heap_Sort_Descending(arr, n);
	//Creat_Max_Heap(arr, n);
	PrintArray(arr, n);
	return 0;
}