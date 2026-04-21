#pragma once 
#include"../common/Node.h"
using namespace std; 
template <typename T>
class Stack
{
private : 
	T data; 
	Node<T>* Top;
	int length{0};
	void print_helper(Node<T>* node) const ; 
public : 
	Stack() : Top(nullptr){}
	bool isEmpty(); 
	bool isFind(T number);
	void push(T number); 
	void print() const ; 
	T pop(); 
	T top(); 
	int size();
};

template<typename T>
void inline Stack<T>::print_helper(Node<T>* node) const 
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->data << " "; 
	print_helper(node->next); 
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
	return (Top == nullptr);
}

template<typename T>
inline bool Stack<T>::isFind(T number)
{
	for (Node<T>* temp = Top; temp != nullptr; temp = temp->next)
	{
		if (temp != nullptr && temp->data == number)
		{
			return true; 
		}
	}
	return false; 
}

template<typename T>
inline void Stack<T>::push(T number)
{
	length++;
	Node<T>* newNode = new Node<T>(number);
	newNode->next = Top; 
	Top = newNode; 
}

template<typename T>
inline void Stack<T>::print() const
{
	print_helper(Top); 
	cout << endl; 
}

template<typename T>
inline T Stack<T>::pop()
{
	//assert(!isEmpty);
	length--;
	Node<T>* delPtr = Top;
	T top = Top->data;
	Top = Top->next; 
	delete delPtr; 
	return top; 
}

template<typename T>
inline T Stack<T>::top() 
{
	return Top->data; 
}

template<typename T>
inline int Stack<T>::size()
{
	return length;
}
