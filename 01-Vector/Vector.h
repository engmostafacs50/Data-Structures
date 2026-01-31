#pragma once
#include<cassert>
template<typename T>
class Vector {
private:
	int size;
	T* arr = nullptr;
public:
	Vector(int size);
	T get(const int index) const;
	void set(const int index, const T number);
	void print() const;
	int find(T value);
};

template<typename T>
inline Vector<T>::Vector(int size)
{
	assert(size > 0);
	this->size = size;
	arr = new T[size];
}

template<typename T>
inline T Vector<T>::get(const int index) const
{
	assert(index >= 0 && index < size);
	return arr[index];
}

template<typename T>
inline void Vector<T>::set(const int index, const T number)
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
