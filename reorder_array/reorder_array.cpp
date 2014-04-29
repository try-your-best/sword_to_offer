//============================================================================
// Name        : reorder_array.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

void ReorderArray(int *data, int len)
{
	int low = 0;
	int high = len-1;
	while(low < high)
	{
		while(low < high && (*(data + low) & 1) != 0)
		{
			low++;
		}
		while(low < high && (*(data+high) & 1) == 0)
		{
			high--;
		}
		if(low < high)
		{
			swap(*(data + low), *(data+high));
		}
	}
}

void PrintArray(int *data, int len)
{
	for(int i = 0; i < len; i++)
	{
		cout <<data[i]<<",";
	}
	cout << endl;
}

void Test()
{
	int data[] = {1,2,3,4,5,6};
	int len = sizeof(data)/sizeof(int);
	ReorderArray(data, len);
	PrintArray(data, len);
}

int main() {
	Test();
	cout << "A" << endl;
	return 0;
}
