#pragma once
#pragma warning(disable : 4996)

#include <vector>

using namespace std;

class CustomString
{
public:
	CustomString();
	CustomString(const char* data);
	CustomString(const CustomString& other);
	~CustomString();

	int size() const;
	int length() const;
	int capacity() const;

	//CustomString& operator=(const CustomString& other);
	CustomString& operator=(CustomString other);
	bool operator==(const CustomString& other) const;

	CustomString substr(int start, int count) const;
	CustomString append(const char* appData);
	int find(const char* findData);
	vector<CustomString> split(const char* splitData);
private:
	void _init();
	void _expand();
	// Ĭ�ϴ�СΪ0
	int _size;
	// Ĭ������Ϊ16
	int _capacity;
	// Ĭ�Ϸ����СΪ16���ڴ�ռ�
	char* _data{nullptr};
};

