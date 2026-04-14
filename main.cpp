#include<iostream>
#include<algorithm>
#include "01-Vector/Vector.h"
#include "03-stack/stack.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
#include"DoublyLinkedList/DoublyLinkedList.h"
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
	//Vector<int>vec(7);
	//for (int i = 0; i < vec.get_size(); i++)
	//{
	//	cout << "Entern num \n"; 
	//	int num; cin >> num; 
	//	vec.set(i, num); 
	//}
	//cout << "array before sorted\n";
	//vec.print();
	//cout << "array after sorted\n";
	//mergeSort(vec.data(), vec.begin(), vec.end()); 
	//vec.print();

	//LinkedList<int>list; 
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << "Enter num "; 
	//	int num; cin >> num; 
	//	list.insert_end(num); 
	//}
	//list.print(); 

	//cout << "Size is " << list.get_lenght() << endl; 

	////cout << "Enter number which you search obout that "; 
	////int num; cin >> num; 
	////if (list.isFind(num))
	////	cout << "y";
	////else
	////	cout << "n"; 

	//cout << "Enter item which you need insert after it then number "; int num , item ; cin >> item >> num ;
	//cout << endl; 
	//list.insert_afterItem(item, num); 
	//list.print();
	//int num; cin >> num; 
	//list.delete_element(num); 
	//list.print();
	//cout << "Size is " << list.get_lenght() << endl;
	Vector<int>vec(6); 
	vec.set(0 ,4);
	vec.set(1 , 2);
	vec.set(2 , 5);
	vec.set(3, 1);
	vec.set(4 ,3);
	vec.set(5 , 0);

	bubbleSort(vec.data(),6); 
	//DoublyLinkedList<int>doubleList;
	//doubleList.insert_front(5);
	//doubleList.insert_front(4);
	//doubleList.insert_front(3);
	//doubleList.insert_front(2);
	//doubleList.insert_front(1);
	//doubleList.print(); 
	//doubleList.del_element(2); 
	//doubleList.del_element(5);
	//doubleList.del_element(1);
	//doubleList.print();
}