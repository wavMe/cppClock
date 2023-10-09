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

	int Size() const;
	int Length() const;
	int Capacity() const;

	//CustomString& operator=(const CustomString& other);
	CustomString& operator=(CustomString other);
	bool operator==(const CustomString& other) const;

	CustomString Substr(int start, int count) const;
	CustomString Append(const char* appData);
	int Find(const char* findData);
	vector<CustomString> Split(const char* splitData);
private:
	void DefualtInit();
	// Ĭ�ϴ�СΪ0
	int _size;
	// Ĭ������Ϊ16
	int _capacity;
	// Ĭ�Ϸ����СΪ16���ڴ�ռ�
	char* _data{nullptr};
};

