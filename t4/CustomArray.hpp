#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class CustomArray
{
	friend std::ostream& operator<<(ostream& cout, const CustomArray<T>& obj) {
		for (size_t i = 0; i < obj._size; i++)
			cout << obj._data[i] << " ";
		return cout;
	}

public:
	CustomArray() { _init(); }
	CustomArray(const CustomArray<T>& other)
	{
		clearDeeply();
		_size = other._size;
		_capacity = other._capacity;
		_data = new T[_capacity];
		memcpy(_data, other._data, sizeof(T) * _size);
	}
	CustomArray(CustomArray<T>&& other) noexcept
	{
		clearDeeply();
		_size = other._size;
		_capacity = other._capacity;
		_data = other._data;
		other.clearLightly();
	}
	~CustomArray() { clearDeeply(); }

	CustomArray& operator=(const CustomArray<T>& other)
	{
		if (this != &other)
		{
			clearDeeply();
			_size = other._size;
			_capacity = other._capacity;
			_data = new T[_capacity];
			memcpy(_data, other._data, sizeof(T) * _size);
		}
		return *this;
	}
	CustomArray& operator=(CustomArray<T>&& other) noexcept
	{
		if (this != &other)
		{
			clearDeeply();
			_size = other._size;
			_capacity = other._capacity;
			_data = other._data;
			other.clearLightly();
		}
		return *this;
	}
	T& operator[](size_t index)
	{
		if (index >= _size)
			throw out_of_range("Index out of range");
		return *(_data + index);
	}

	void reserve(size_t newCapacity)
	{
		T* newData = new T[newCapacity];
		_capacity = newCapacity;
		if (_data)
		{
			memcpy(newData, _data, sizeof(T) * _size);
			delete[] _data;
		}
		_data = newData;
	}

	void clearLightly()
	{
		_size = 0;
		_capacity = 0;
		if (_data != nullptr)
			_data = nullptr;
	}
	void clearDeeply()
	{
		_size = 0;
		_capacity = 0;
		if (_data != nullptr)
		{
			delete[] _data;
			_data = nullptr;
		}
	}

	void push(T value)
	{
		if (_size >= _capacity)
			_expand();
		_data[_size] = value;
		_size++;
	}
	T pop()
	{
		if (_size <= 0)
			throw out_of_range("Index out of range");
		return _data[--_size];
	}

	void insert(size_t index, T value)
	{
		if (_size >= _capacity)
			_expand();

		if (index <= _size)
		{
			for (size_t i = _size - 1; i >= index; i--)
				_data[i + 1] = _data[i];

			_data[index] = value;
			_size++;
		}
	}
	void remove(size_t index)
	{
		if (index >= _size)
			return;

		for (size_t i = index; i < _size - 1; i++)
			_data[i] = _data[i + 1];

		_size--;
	}


	size_t find(T value)
	{
		for (size_t i = 0; i < _size; i++)
		{
			if (_data[i] == value)
				return i;
		}

		return -1;
	}
private:
	void _init()
	{
		_size = 0;
		_capacity = 0;
		_data = nullptr;
	}
	void _expand()
	{
		if (_size >= _capacity)
			_capacity = _size ? _capacity * 2 : 2;

		T* newData = new T[_capacity];
		if (_data != nullptr)
		{
			memcpy(newData, _data, sizeof(T) * _size);
			delete[] _data;
		}
		_data = newData;
	}

	size_t _size;
	size_t _capacity;
	T* _data;
};
