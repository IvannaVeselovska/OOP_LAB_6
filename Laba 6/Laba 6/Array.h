#pragma once
template<typename T> class Array
{
private:
	T* array;
	int size;
	void InitDefault(T value);
public:
	Array(int size, T value);
	~Array();
	void SetValue(T value, int position);
	T &operator [](int i);
	const int GetSize()const;
	void Insert(T value, int position);
	void Delete(int position);
};

template<typename T>
inline void Array<T>::InitDefault(T value)
{
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = value;
	}
}

template<typename T>
inline Array<T>::Array(int size, T value)
{
	this->size = size;
	this->array = new T[this->size];
	InitDefault(value);
}

template<typename T>
inline Array<T>::~Array()
{
	delete[] this->array;
}

template<typename T>
inline void Array<T>::SetValue(T value, int position)
{
	this->array[position] = value;
}

template<typename T>
inline T & Array<T>::operator [](int i)
{
	if (i >= 0 && i < this->size) {
		return this->array[i];
	}
	throw "You went beyond the array";
}

template<typename T>
inline const int Array<T>::GetSize() const
{
	return this->size;
}

template<typename T>
inline void Array<T>::Insert(T value, int position)
{
	if (position<0 || position>size)
	{
		throw "You went beyond the array";
	}
	T* new_arr = new T[size + 1];
	for (int i = 0; i < position; i++)
	{
		new_arr[i] = this->array[i];
	}
	new_arr[position] = value;
	for (int i = position + 1; i < size + 1; i++)
	{
		new_arr[i] = this->array[i - 1];
	}
	size++;
	this->array = new_arr;
}

template<typename T>
inline void Array<T>::Delete(int position)
{
	if (position < 0 || position > size)
	{
		throw "You went beyond the array";
	}
	T* new_arr = new T[size + 1];
	for (int i = 0; i < position; i++)
	{
		new_arr[i] = this->array[i];
	}
	for (int i = position; i < size - 1; i++)
	{
		new_arr[i] = this->array[i + 1];
	}
	size--;
	this->array = new_arr;
}
