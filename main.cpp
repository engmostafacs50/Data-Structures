#include<iostream>
#include<algorithm>
#include "01-Vector/Vector.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
using namespace std; 
int main()
{
	int n = 7;
	Vector<int>v1(n);
	v1.set(0, 3);
	v1.set(1, 5);
	v1.set(2, 3);
	v1.set(3, 9);
	v1.set(4, 1);
	v1.set(5, 7);
	v1.set(6, 0);
	merge_sort(v1.data(), 0, 6);
	v1.print(); 
}