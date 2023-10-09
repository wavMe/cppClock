//第3题_数据结构
//实现string

#include <vector>

#include "CustomString.h"

int main()
{
	CustomString s1 = "abc123";

	// construct
	CustomString empty = CustomString();
	CustomString str = CustomString("test1,test2,test3,test4,test5");
	CustomString str2 = CustomString(str);
	CustomString str3(str2);
	CustomString str4 = str3;

	// length
	int len = str.Length();

	// substr
	CustomString subStr = str.Substr(0, 11);

	// append
	CustomString appStr = str.Append(",append");

	// operator=
	CustomString str5;
	str5 = str4;

	// operator==
	bool equal = str == str2;

	// find
	int index = str.Find("append");

	// split
	vector<CustomString> strs = str.Split(",");

	return 0;
}
