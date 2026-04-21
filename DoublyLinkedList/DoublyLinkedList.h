#pragma once
#include <iostream>
using namespace std;
template<typename T>
class  DoublyNode {
public :
	T data; 
	DoublyNode<T>* next{nullptr};
	DoublyNode<T>* previous{nullptr};
	DoublyNode(T number) : data(number){}
};
template<typename T>
class DoublyLinkedList
{
private:
	DoublyNode<T>* head{nullptr};
	DoublyNode<T>* tail{nullptr};
	int length{0};
public:
	bool isEmpty();
	void insert_end(T number); 
	void insert_front(T number); 
	void print() const;
	void rev_print() const;
	void del_element(T number); 
	bool isFound(T number); 
};

template<typename T>
inline bool DoublyLinkedList<T>::isEmpty()
{
	return (head == nullptr);
}

template<typename T>
inline void DoublyLinkedList<T>::insert_end(T number)
{
	DoublyNode<T>* newNode = new DoublyNode<T>(number);
	length++;
	if (isEmpty())
	{
		tail = head = newNode; 
	}
	else
	{
		tail->next = newNode; 
		newNode->previous = tail;
		tail = newNode; 
	}
}

template<typename T>
inline void DoublyLinkedList<T>::insert_front(T number)
{
	DoublyNode<T>* newNode = new DoublyNode<T>(number);
	length++;
	if (isEmpty())
	{
		tail = head = newNode;
	}
	else
	{
		head->previous = newNode; 
		newNode->next = head; 
		head = newNode;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::print() const
{
	for (DoublyNode<T>* temp = head; temp != nullptr; temp = temp->next)
	{
		cout << temp->data << " ";
	}
	cout << endl;
}

template<typename T>
inline void DoublyLinkedList<T>::rev_print() const
{
	for (DoublyNode<T>* temp = tail; temp != nullptr; temp = temp->previous)
	{
		cout << temp->data << " ";
	}
	cout << endl;
}

template<typename T>
inline void DoublyLinkedList<T>::del_element(T number)
{
	assert(!isEmpty());
	assert(isFound(number)); 
	length--; 
	DoublyNode<T>* del_ptr; 
	if (number == head->data)
	{
		del_ptr = head; 
		head = head->next; 
		head->previous = nullptr; 
		delete del_ptr; 
	}
	else
	{
		for (DoublyNode<T>* temp = head; temp != nullptr; temp = temp->next)
		{
			if (temp->next != nullptr && temp->next->data == number)
			{
				del_ptr = temp->next;
				temp->next = del_ptr->next; 
				if (del_ptr->next != nullptr)
					del_ptr->next->previous = temp;
				else
					tail = temp;
				delete del_ptr;
				return;
			}
		}
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::isFound(T number)
{
	DoublyNode<T>* first = head;
	while (first != nullptr)
	{
		if (first->data == number)
		{
			return true;
		}
		first = first->next; 
	}
	return false; 
}