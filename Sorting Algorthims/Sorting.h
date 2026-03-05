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

template <typename T>
void BubbleSort(T* arr, int size)
{
	bool isOrdered = false; 
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size-i-1; j++) {
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]); 
				isOrdered = true; 
			}
		}
		if (!isOrdered)
		{
			break; 
		}
	}
} 

template<typename T> //o(n)
void merge(T* arr, size_t left, size_t middle ,size_t right)
{
	int size_arr1 = middle - left + 1; 
	int size_arr2 = right - middle ; 

	T* arr1 = new T[size_arr1]; 
	T* arr2 = new T[size_arr2]; 
	for (int i = 0; i < size_arr1; i++)
		arr1[i] = arr[left+i]; 
	for (int j = 0; j < size_arr2; j++)
		arr2[j] = arr[middle+1+j];
	size_t i, j;
	i = j = 0;
	size_t k = left; 
	while (i < size_arr1 && j < size_arr2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i]; 
			k++; i++;
		}
		else
		{
			arr[k] = arr2[j];
			k++; j++;
		}
	}

	while (i < size_arr1)
	{
		arr[k] = arr1[i]; 
		k++; i++;
	}
	while (j < size_arr2)
	{
		arr[k] = arr2[j];
		k++; j++;
	}
	delete[]arr1;
	delete[]arr2;
}

template<typename T> // O(nlogn)
void merge_sort(T* arr, size_t l, size_t r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2; 
		merge_sort(arr, l, mid); 
		merge_sort(arr,mid+1, r);
		merge(arr, l, mid , r); 
	}
}