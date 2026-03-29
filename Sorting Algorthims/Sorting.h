#pragma once
#include<algorithm>

template<typename T>
void insertionSort(T* arr, int size)
{
	for (size_t i = 1 , j ; i < size;i++)
	{
		T temp = arr[i]; 
		for (j =i ; j > 0 && arr[j-1] >temp ; j--)
		{
			arr[j] = arr[j - 1]; 
		}
		arr[j] = temp ; 
	}
}

template<typename T>
void selectionSort(T* arr, int size)
{
	int minIndex = 0;
	for (size_t i = 0, j; i < size - 1; i++)
	{
		for (j = i + 1; j < size ; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]); 
	}
}

template<typename T>
void bubbleSort(T* arr, int size)
{
	bool isOrdered = false;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1;j++) 
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j + 1]);
				isOrdered = true;
			}
		}
		if (!isOrdered)
			break;
	}
}
template<typename T>
void merge(T* arr, int left, int mid, int right)
{
	int sizeArr1 = mid - left + 1;
	int sizeArr2 = right - mid;

	T* arr1 = new T[sizeArr1];
	T* arr2 = new T[sizeArr2];

	for (size_t i = 0; i < sizeArr1; i++)
	{
		arr1[i] = arr[i + left];
	}
	for (size_t i = 0; i < sizeArr2; i++)
	{
		arr2[i] = arr[i + mid + 1];
	}
	int i = 0, j = 0;
	int k = left;
	while (i < sizeArr1 && j < sizeArr2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else
		{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while (i < sizeArr1)
	{
		arr[k] = arr1[i];
		i++;k++;
	}
	while (j < sizeArr2)
	{
		arr[k] = arr2[j];
		j++;k++;
	}
}
template<typename T>
void mergeSort(T*arr , int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2; 
		mergeSort(arr , left, mid); 
		mergeSort(arr ,mid+1, right);
		merge(arr , left, mid, right); 
	}
}
template<typename T>
int partition(T*arr ,int left ,int right)
{
	T pivot = arr[left]; 
	int l = left + 1; 
	int h = right; 
	while (true)
	{
		while (l <= h && pivot >= arr[l])
		{
			l++;
		}
		while (l <= h && pivot < arr[h])
		{
			h--; 
		}
		if (l > h)
		{
			break; 
		}
		swap(arr[l], arr[h]); 
	}
	swap(arr[left], arr[h]);
	return h; 
}

template<typename T>
void quickSort(T*arr ,int low , int high) 
{
	if (low < high)
	{
		int right = partition(arr, low, high);
		quickSort(arr , low, right-1);
		quickSort(arr , right + 1, high);
	}
}