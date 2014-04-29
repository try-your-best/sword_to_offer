#include <iostream>
#include <algorithm>
using namespace std;

bool IsContinuous(int *data, int len)
{
	if(data == NULL || len <= 0)
		return false;
	sort(data, data+len);
	int num_of_zero = 0;
	for(int i = 0; i < len; i++)
	{
		if(data[i] == 0)
			num_of_zero++;
	}
	int small = num_of_zero;
	int big = small+1;
	int num_of_gap = 0;
	while(big < len)
	{
		if(data[big] == data[small])
		{
			return false;
		}
		num_of_gap += data[big] - data[small] - 1;
		small = big;
		big++;
	}
	return (num_of_gap <= num_of_zero);
}

void Test()
{
	int data[] = {1,3,5,0,8};
	int len = sizeof(data)/sizeof(int);
	cout << IsContinuous(data, len) << endl;
}

int main() {
	Test();
	return 0;
}
