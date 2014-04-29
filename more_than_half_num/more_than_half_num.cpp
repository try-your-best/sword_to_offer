#include <iostream>
using namespace std;

bool CheckMoreThanHalf(int *data, int len, int result);

int MoreThanHalfNum(int *data, int len)
{
	if(data == NULL || len == 0)
		return 0;
	int result = data[0];
	int times = 1;
	for(int i = 1; i < len; i++)
	{
		if(times == 0)
		{
			result = data[i];
			times = 1;
		}
		else if(data[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if(CheckMoreThanHalf(data, len, result))
	{
		return result;
	}
	else
	{
		return 0;
	}
}

bool CheckMoreThanHalf(int *data, int len, int result)
{
	int times = 0;
	for(int i = 0; i < len; i++)
	{
		if(data[i] == result)
			times++;
	}
	if(times * 2 <= len)
		return false;
	else
		return true;
}

void Test()
{
	int data[] = {1,2,2,2,2,3,3};
	cout << MoreThanHalfNum(data, sizeof(data)/sizeof(int)) << endl;
}

int main() {
	Test();
	return 0;
}
