#include<iostream>
#include "01-Vector/Vector.h"
using namespace std; 
int main()
{
	Vector<int> v1(3); 

	v1.set(2, 5); 
	v1.set(0, 1);
	v1.set(1, 3); 

	v1.print(); 
}