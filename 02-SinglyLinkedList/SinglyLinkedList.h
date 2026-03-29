#pragma once
#include <iostream>
#include<exception>
#include<cassert>
using namespace std;

template <typename T>
class Node
{
public :
	T data; 
	Node* next;
	Node(T number) : data(number) , next(nullptr) {}
};
template <typename T>
class LinkedList 
{
private :
	Node<T>* head; 
	Node<T>* tail;
	unsigned int length{0};
	void print_helper(Node<T>* node)const;
	void reverse_print_helper(Node<T>* node)const;
public :
	LinkedList(); 
	//~LinkedList();
	bool isEmpty();
	bool isFind(T number);
	void insert_front(T number);
	void insert_end(T number);
	void insert_beforeItem(T item, T number); 
	void print() const ; 
	void reverse_print() const ; 
	unsigned int get_lenght()const; 
};

template<typename T>
inline void LinkedList<T>::print_helper(Node<T>* node) const
{
	if (node == nullptr)
		return; 
	cout << node->data << " ";
	print_helper(node->next);
}

template<typename T>
inline void LinkedList<T>::reverse_print_helper(Node<T>* node) const
{
	if (node == nullptr)
		return;
	reverse_print_helper(node->next);
	cout << node->data << " ";
}

template<typename T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr; 
	tail = nullptr; 
}

template<typename T>
inline bool LinkedList<T>::isEmpty()
{
	return (head == nullptr);
}

template<typename T>
inline bool LinkedList<T>::isFind(T number)
{
	Node<T>* temp = head; 
	while (temp != nullptr)
	{
		if (temp->data == number)
		{
			return true; 
		}
		temp = temp->next;
	}
	return false; 
}

template<typename T>
inline void LinkedList<T>::insert_front(T number)
{
	length++; 
	Node<T>* newNode = new Node<T>(number);
	if(isEmpty())
	{
		tail = head = newNode; 
	}
	else
	{
		newNode->next = head; 
		head = newNode; 
	}
}

template<typename T>
inline void LinkedList<T>::insert_end(T number)
{
	length++;
	Node<T>* newNode = new Node<T>(number);
	if (isEmpty())
	{
		tail = head = newNode;
	}
	else
	{
		tail->next = newNode; // last node point to new node ; 
		tail = newNode; 
	}
}

template<typename T>
inline void LinkedList<T>::insert_beforeItem(T item, T number)
{
	assert(isFind(item));
	length++;
	Node<T>* newNode = new Node<T>(number);
	if (item == head->data)
	{
		this->insert_front(number); 
	}
	else
	{
		for (Node<T>* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->next->data == item && temp->next != nullptr)
			{
				newNode->next = temp->next;
				temp->next = newNode; 
				return; 
			}
		}
	}
}

template<typename T>
inline void LinkedList<T>::print() const
{	
	print_helper(head); 
	cout << endl; 
	//for (Node<T>* temp = head; temp != nullptr; temp = temp->next)
	//{
	//	cout << temp->data << " "; 
	//}
	//cout << endl; 
}

template<typename T>
inline void LinkedList<T>::reverse_print() const
{
	reverse_print_helper(head);
	cout << endl; 
}

template<typename T>
inline unsigned int LinkedList<T>::get_lenght() const
{
	return length;
}

