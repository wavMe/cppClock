#pragma once
#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct CustomListNode
{
	friend ostream& operator<<(ostream& cout, const CustomListNode<T>& obj)
	{
		cout << obj.value;
		return cout;
	}
public:
	T value;
	CustomListNode<T>* pre = nullptr;
	CustomListNode<T>* next = nullptr;
};

template<class T>
class CustomList
{
	friend ostream& operator<<(ostream& cout, const CustomList<T>& obj)
	{
		CustomListNode<T>* cur = obj._head->next;
		while (cur != obj._tail)
		{
			cout << cur->value;
			if(cur->next != obj._tail)
				cout << "->";
			cur = cur->next;
		}
		return cout;
	}
public:
	CustomList() 
	{ 
		_head = new CustomListNode<T>();
		_tail = new CustomListNode<T>();
		_head->next = _tail;
		_tail->pre = _head;
	}
	~CustomList() 
	{ 
		popAll();
		delete _head;
		_head = nullptr;
		delete _tail;
		_tail = nullptr;
	}

	void remove(CustomListNode<T>* removeNode)
	{
		removeNode->pre->next = removeNode->next;
		removeNode->next->pre = removeNode->pre;
		delete removeNode;
	}

	void push(T value)
	{
		CustomListNode<T>* pushNode = new CustomListNode<T>();
		pushNode->value = value;
		pushNode->pre = _tail->pre;
		pushNode->next = _tail;
		_tail->pre->next = pushNode;
		_tail->pre = pushNode;
	}

	T pop()
	{
		CustomListNode<T>* popNode = _tail->pre;

		T value = popNode->value;
		remove(popNode);
		return value;
	}

	vector<T> popAll()
	{
		vector<T> values;
		while (_head->next != _tail)
			values.push_back(pop());

		return values;
	}

	void insert(CustomListNode<T>* insertNode, T value)
	{
		CustomListNode<T>* newNode = new CustomListNode<T>();
		newNode->value = value;
		newNode->pre = insertNode;
		newNode->next = insertNode->next;
		insertNode->next->pre = newNode;
		insertNode->next = newNode;
	}

	CustomListNode<T>* find(T value)
	{
		CustomListNode<T>* cur = _head->next;
		while (cur != _tail)
		{
			if (cur->value == value)
				return cur;
		}
		return nullptr;
	}
private:
	CustomListNode<T>* _head = nullptr;
	CustomListNode<T>* _tail = nullptr;
};
