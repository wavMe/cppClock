//第4题_数据结构
//实现array（可变数组）以及双向链表
#include <iostream>

#include "CustomArray.hpp"
#include "CustomList.hpp"

using namespace std;

int main()
{
	cout << "=====CustomArray=====" << endl;
	CustomArray<int> arr = CustomArray<int>();
	arr.reserve(4);

	arr.push(1);
	arr.push(2);
	cout << arr << endl;

	CustomArray<int> arr2(arr);
	CustomArray<int> arr3 = move(arr2);
	CustomArray<int> arr4;
	arr4 = arr3;
	arr4 = move(arr3);

	arr.insert(1, 3);
	cout << arr << endl;

	int index = static_cast<int>(arr.find(3));
	cout << "3's index:" << index << endl;

	arr.remove(1);
	cout << arr << endl;

	arr.pop();
	cout << arr << endl;

	arr.clearDeeply();
	cout << arr << endl;

	cout << "=====CustomList=====" << endl;
	CustomList<int> list = CustomList<int>();
	list.push(1);
	list.push(2);
	cout << list << endl;

	CustomListNode<int>* findNode = list.find(1);
	cout << *findNode << endl;

	list.insert(findNode, 3);
	cout << list << endl;
	
	list.remove(findNode);
	cout << list << endl;

	vector<int> values = list.popAll();
	for (int i = 0; i < values.size(); i++)
		cout << values[i] << " ";

	return 0;
}