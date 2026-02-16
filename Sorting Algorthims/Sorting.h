#pragma once
#include<algorithm>
/*
Time complexity is O(n^2)
What's best case ?
	if temp >= arr[j-1] in this case time complexity is O(n)
*/
template <typename T>
void InsertionSort(T* arr, int size)
{
	for (size_t i = 1, j; i < size; i++)
	{
		T temp = arr[i];
		for (j = i; j > 0 && temp < arr[j - 1]; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;

	}
}

template <typename T>
void SelectionSort(T* arr, int size)
{
	int minIndex = 0; 
	for (size_t i = 0 , j; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j; 
			}
		}
		swap(arr[i], arr[minIndex]); 
	}
}