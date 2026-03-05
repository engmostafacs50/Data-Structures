#include<iostream>
#include<algorithm>
#include "01-Vector/Vector.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
using namespace std; 
int main()
{
	SinglyLinkedList<int>List1;
	List1.insert_end(2);
	List1.insert_end(3);
	List1.insert_end(9);
	SinglyLinkedList<int>List2;
	List2.insert_end(1);
	List2.insert_end(6);
	List2.insert_end(7);

	SinglyLinkedList<int>list3 = SinglyLinkedList<int>::mergeTwoSortedList(List1, List2);
	list3.print();
}