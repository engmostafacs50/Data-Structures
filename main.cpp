#include<iostream>
#include<algorithm>
#include "01-Vector/Vector.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
using namespace std; 
int main()
{
//	int n = 7;
//	Vector<int>v1(n);
//	v1.set(0, 3);
//	v1.set(1, 5);
//	v1.set(2, 3);
//	v1.set(3, 9);
//	v1.set(4, 1);
//	v1.set(5, 7);
//	v1.set(6, 0);
//
//	cout << "Data before Sorting\n"; 
//	v1.print();
//	BubbleSort(v1.data(), v1.get_size());
//	cout << "Data after Sorting\n"; 
//	v1.print();
	SinglyLinkedList<int>SLL;
	SLL.insert_end(1);
	SLL.insert_end(2);
	SLL.insert_end(3);
	SLL.insert_end(4);

	//cout << SLL.get_nt(1); 
	//cout << SLL.get_nt(2); 
	//cout << SLL.get_nt(3); 
	//cout << SLL.get_nt(4); 
}