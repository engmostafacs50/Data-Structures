#pragma once
#include<cassert>
#include<algorithm>
template<typename T>
class Vector {
private:
	int size{0}; // user size 
	int capacity{0}; // actual size 
	T* arr = nullptr;
	void expand_capacity();
public:
	Vector(T size);
	T at(const T index) const;
	void set(const T index, const T number);
	void print() const;
	int find(T value);
	void push_back(T number);
	T front()const; 
	T back() const;
	void insert(const size_t index, const T number);
	void left_rotation(); 
	void right_rotation(); 
	T erase(int index) ; 
	//int length();
};

template<typename T>
inline Vector<T>::Vector(T size)
{
	assert(size > 0);
	this->size = size; 
	capacity = size + 10; 
	arr = new T[capacity];
}

template<typename T>
inline T Vector<T>::at(const T index) const
{
	assert(index >= 0 && index < size);
	return arr[index];
}



template<typename T>
inline void Vector<T>::set(const T index, const T number)
{
	assert(index >= 0 && index < size);
	arr[index] = number;
}

template<typename T>
inline void Vector<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

template<typename T>
inline int Vector<T>::find(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
			return i;
	}
	return -1;
}

template<typename T>
inline void Vector<T>::push_back(T number) // O(1)
{
	if (size == capacity)
		expand_capacity(); 
	arr[size++] = number;
}

template<typename T>
inline T Vector<T>::front() const
{
	return arr[0]; 
}

template<typename T>
inline T Vector<T>::back() const
{
	return arr[size-1];
}

template<typename T>
inline void Vector<T>::expand_capacity()
{
	capacity *= 2; 
	T* new_arr = new T[capacity]; 
	for (int i = 0; i < size; i++)
		new_arr[i] = arr[i]; 
	swap(arr, new_arr); // swap addresses not data 
	delete[] new_arr;   
}

template<typename T>
inline void Vector<T>::insert(const size_t index, const T number)
{
	assert(index >= 0 && index <= size);

	if (size == capacity)
		expand_capacity(); 
	// Shifting to right untill index only

	
	for (int i = size - 1; i >= index; i--)
		arr[i + 1] = arr[i]; // --> { 0 , 1 ,index, 2, 3} // index is empty pr carp Val
	arr[index] = number; 
	size++; 
}

template<typename T>
inline void Vector<T>::left_rotation()
{
	T temp = this->front(); 
	for (int i = 0; i < size - 1; i++)
		arr[i] = arr[i + 1]; 
	arr[size - 1] = temp; 
}

template<typename T>
inline void Vector<T>::right_rotation()
{
	T temp = this->back(); 
	for (int i = size - 2; i >= 0; i--)
		arr[i + 1] = arr[i]; 
	arr[0] = temp; 
}

template<typename T>
inline T Vector<T>::erase(int index)
{
	assert(index >= 0 && index < size);
	T* new_arr = new T[size]; 
	T deletedNumber = 0; 
	for (int i = 0; i < size; i++)
	{
		if (index == i)
		{
			new_arr[i] = arr[i + 1]; 
			deletedNumber = arr[i]; 
			i++; 
		}
		else
		{
			new_arr[i] = arr[i]; 
		}
	}
	size--; 
	swap(arr, new_arr); 
	delete[] new_arr; 
	return deletedNumber; 
}



//template<typename T>
//inline int Vector<T>::length()
//{
//	return size; 
//}

