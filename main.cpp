#include<iostream>
#include<algorithm>
#include "01-Vector/Vector.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
using namespace std; 
int main()
{
	//SinglyLinkedList<int>List1;
	//List1.insert_end(2);
	//List1.insert_end(3);
	//List1.insert_end(9);
	//List1.print(); 
	//cout << endl; 
	//List1.deleteFirstNode(); 
	//List1.print();
	Vector<int>vec(7);
	for (int i = 0; i < vec.get_size(); i++)
	{
		cout << "Entern num \n"; 
		int num; cin >> num; 
		vec.set(i, num); 
	}
	cout << "array before sorted\n";
	vec.print();
	cout << "array after sorted\n";
	quickSort(vec.data(), vec.begin(), vec.end()); 
	vec.print();
}