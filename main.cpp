#include<iostream>
#include "01-Vector/Vector.h"
using namespace std; 
int main()
{
	int n = 3; 
	Vector<int>v1(n); 
	for (int i = 0; i < n; i++)
	{
		v1.set(i, i); 
	}
	v1.push_back(12.5);
	
	v1.print();
 }