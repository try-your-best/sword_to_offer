//============================================================================
// Name        : two_numbers_with_sum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool FindTwoNumbersWithSum(int data[], int len, int sum, int &num1, int &num2)
{
	bool found = false;
	if(data == NULL || len < 1)
		return found;
	int low = 0;
	int high = len -1;
	while(low < high)
	{
		long long cur_sum = data[low] + data[high];
		if(cur_sum == sum)
		{
			num1 = data[low];
			num2 = data[high];
			found = true;
			break;
		}
		else if(cur_sum < sum)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
	return found;
}

void Test()
{
	int data[] = {1,2,4,7,11,15};
	int len = sizeof(data)/sizeof(int);
	int num1 = 0, num2 = 0;
	if(FindTwoNumbersWithSum(NULL, len, 15, num1, num2))
	{
		cout << num1  <<"," << num2 << endl;
	}
	else
	{
		cout <<"not found" << endl;
	}
}

int main() {
	Test();
	return 0;
}
