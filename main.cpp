#include<iostream>
#include<algorithm>
#include <cctype>
#include <cmath>
#include "01-Vector/Vector.h"
#include "03-stack/stack.h"
#include"Sorting Algorthims/Sorting.h"
#include"02-SinglyLinkedList/SinglyLinkedList.h"
#include"DoublyLinkedList/DoublyLinkedList.h"
//#include"./Tree/BinaryTree.h"

using namespace std;
struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};
int height(node* r)
{
	if (r == nullptr)
		return -1; 
	int leftHeight = height(r->left);
	int rightHeight = height(r->right);
	return 1 + max(leftHeight, rightHeight); 
}
void print(node* r)
{
	if (r == NULL)
		return;
	print(r->left);
	cout << r->data << " "; 
	print(r->right);
}
int leafs = 0; 
int leafNumbers(node* r)
{
	if (r == nullptr)
		return 0; 
	if (r->left == nullptr && r->right == nullptr)
		leafs++; 
	leafNumbers(r->left);
	leafNumbers(r->right);

	return leafs; 
}
int minNum = INT8_MAX; 
int minVal(node* r)
{
	if (r == nullptr)
		return minNum; 
	if (minNum > r->data)
		minNum = r->data; 
	minVal(r->left);
	minVal(r->right);
}
void clear(node* r)
{
	if (r == nullptr)
		return; 
	clear(r->left);
	clear(r->right);
	delete r; 
}
int precedence(char operand)
{
	if (operand == '+' || operand == '-')
	{
		return 0; 
	}
	else if (operand == '*' || operand == '/')
	{
		return 1; 
	}
	//else if (operand == '(')
	//{
	//	return 2; 
	//}
	return -1; 
}
string convertingToPostfix(string InfixEq)
{
	int len = InfixEq.length(); 
	string postfixEq = "";
	Stack<char>st; 
	for (int i = 0; i < len; i++)
	{
		if (isdigit(InfixEq[i]))
		{
			postfixEq += InfixEq[i]; 
		}
		else
		{
			while (!st.isEmpty() && precedence(InfixEq[i]) <= precedence(st.top()))
			{
				postfixEq += st.pop();
			}
			st.push(InfixEq[i]); 
		}
	}
	while (!st.isEmpty())
	{
		postfixEq += st.pop(); 
	}
	return postfixEq; 
}

int main()
{

	LinkedList<int>ll; 
	ll.insert_end(1); 
	ll.insert_end(2); 
	ll.insert_end(3); 
	ll.insert_end(4); 
	ll.insert_end(5); 
	ll.insert_end(6); 
	ll.insert_end(7);

	ll.print();
	ll.delete_even_elements();
	ll.print(); 
	//node* root = new node(5);
	//root->left = new node(2);
	//root->right = new node(3);
	//root->left->left = new node(4);
	//root->left->right = new node(5);
	//root->right->right = new node(0);
	//print(root); 
	//cout << endl; 
	//cout << "min value is " << minVal(root) << endl;
	//cout << "Height is " << height(root) << endl ;
	//cout << "Nums of leafs is " << leafNumbers(root) << endl ; 

	//clear(root);
	//print(root); 
	//string infix = "13+3*5-8/2"; 
	//string  postfix= convertingToPostfix(infix);
	//Stack<int>st; 
	//int num1 = 0,num2 = 0 ; 
	//int res = 0; 
	//for (int i = 0; i < postfix.length(); i++)
	//{
	//	if (isdigit(postfix[i]))
	//	{
	//		st.push(postfix[i] - '0');
	//	}
	//	else
	//	{
	//		if (st.size() < 2) {
	//			cout << "Invalid Expression";
	//			return -1;
	//		}

	//		int num2 = st.top(); st.pop();
	//		int num1 = st.top(); st.pop();

	//		if (postfix[i] == '+')
	//			st.push(num1 + num2);

	//		else if (postfix[i] == '-')
	//			st.push(num1 - num2);

	//		else if (postfix[i] == '*')
	//			st.push(num1 * num2);

	//		else if (postfix[i] == '/')
	//		{
	//			if (num2 == 0) {
	//				cout << "Division by zero";
	//				return -1;
	//			}
	//			st.push(num1 / num2);
	//		}

	//		else if (postfix[i] == '^')
	//			st.push(pow(num1, num2));
	//	}
	//}
	//cout << st.pop();


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
	//Vector<int>vec(6); 
	//vec.set(0 ,4);
	//vec.set(1 , 2);
	//vec.set(2 , 5);
	//vec.set(3, 1);
	//vec.set(4 ,3);
	//vec.set(5 , 0);

	//bubbleSort(vec.data(),6); 
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