#include<iostream>
#include "01-Vector/Vector.h"
using namespace std; 
int main()
{
	int n = 5; 
	Vector<int>v1(n); 
	for (int i = 0; i < n; i++)
	{
		v1.set(i, i); 
	}
	v1.find_transportation(3); // {0 , 1 , 2  , 3 , 4 }
	v1.print(); // {0 , 1 , 3 , 2 , 4}
 }