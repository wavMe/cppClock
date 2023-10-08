//第3题_数据结构
//实现string

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
	int len = str.length();

	// substr
	CustomString subStr = str.substr(0, 11);

	// append
	CustomString appStr = str.append(",append");

	// operator=
	CustomString str5;
	str5 = str4;

	// operator==
	bool equal = str == str2;

	// find
	int index = str.find("append");

	// split
	vector<CustomString> strs = str.split(",");

	return 0;
}
