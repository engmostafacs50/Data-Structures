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
	v1.erase(3); 
	v1.print(); 
 }