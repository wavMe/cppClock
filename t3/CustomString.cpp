#include "CustomString.h"

#include <stdexcept>
#include <cstring>
#include <algorithm>

CustomString::CustomString()
{
	DefualtInit();
	_data[_size] = '\0';
}
CustomString::CustomString(const char* data)
{
	DefualtInit();
	_size = static_cast<int>(strlen(data));
	if (_size >= _capacity)
	{
		while (_size >= _capacity)
			_capacity *= 2;

		delete[] _data;
		_data = new char[_capacity];
	}
	memcpy(_data, data, sizeof(char) * (_size + 1));
}
CustomString::CustomString(const CustomString& other)
{
	DefualtInit();
	_size = other._size;
	_capacity = other._capacity;

	delete[] _data;
	_data = new char[_capacity];

	memcpy(_data, other._data, sizeof(char) * (_size + 1));
}
CustomString::~CustomString() { delete[] _data; }

int CustomString::Size() const { return _size; }
int CustomString::Length() const { return _size; }
int CustomString::Capacity() const { return _capacity; }

//CustomString& CustomString::operator=(const CustomString& other)
//{
//	//Ⅰ
//	if (*this == other)
//	{
//		return *this;
//	}
//	_size = other._size;
//	_capacity = other._capacity;
//
//	delete[] _data;
//	_data = new char[_capacity];
//
//	memcpy(_data, other._data, sizeof(char) * (_size + 1));
//
//	return *this;
//}
// Ⅱ copy-and-swap
CustomString& CustomString::operator=(CustomString other)
{
	swap(_size, other._size);
	swap(_capacity, other._capacity);
	swap(_data, other._data);

	return *this;
}
bool CustomString::operator==(const CustomString& other) const
{
	if (_size != other._size)
		return false;
	return (memcmp(_data, other._data, _size) == 0);
}

CustomString CustomString::Substr(int start, int count) const
{
	if (start < 0 || start > _size || count < 0 || start + count > _size)
	{
		throw out_of_range("Invalid index or count in substr");
	}

	char* subData = new char[count + 1];
	char* startData = _data + start;
	memcpy(subData, startData, sizeof(char) * count);
	subData[count] = '\0';

	CustomString subStr = CustomString(subData);
	delete[] subData;
	return subStr;
}

CustomString CustomString::Append(const char* appData)
{
	int oriSize = _size;
	char* oriData = new char[_size + 1];
	memcpy(oriData, _data, sizeof(char) * (_size + 1));

	int appSize = static_cast<int>(strlen(appData));
	_size += appSize;

	if (_size >= _capacity)
	{
		while (_size >= _capacity)
			_capacity *= 2;

		delete[] _data;
		_data = new char[_capacity];
	}

	// 原始data
	memcpy(_data, oriData, sizeof(char) * oriSize);
	// 新增data
	memcpy(_data + oriSize, appData, sizeof(char) * (appSize + 1));

	return _data;
}

int CustomString::Find(const char* findData)
{
	CustomString findStr = CustomString(findData);
	int findSize = findStr.Size();

	for (int start = 0; start < _size - findSize + 1; start++)
	{
		if (Substr(start, findSize) == findStr)
		{
			return start;
		}
	}

	return -1;
}

vector<CustomString> CustomString::Split(const char* splitData)
{
	char* oriData = new char[_size + 1];
	memcpy(oriData, _data, sizeof(char) * (_size + 1));

	vector<CustomString> strs;
	char* str = strtok(oriData, splitData);
	while (str != NULL)
	{
		strs.push_back(str);
		str = strtok(NULL, splitData);
	}

	return strs;
}

void CustomString::DefualtInit()
{
	// 默认大小为0
	 _size = 0;
	// 默认容量为16
	 _capacity = 16;
	// 默认分配大小为16的内存空间
	_data = new char[_capacity];
}