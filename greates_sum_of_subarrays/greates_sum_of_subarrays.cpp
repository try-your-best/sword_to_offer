#include <iostream>
#include <climits>
using namespace std;

int GreatestSumOfSubarrays(int data[], int len)
{
	int max_sum = INT_MIN;
	int cur_sum = 0;
	for(int i = 0; i < len; i++)
	{
		if(cur_sum < 0)
		{
			cur_sum = 0;
			cur_sum += data[i];
		}
		else
		{
			cur_sum += data[i];
		}
		if(cur_sum > max_sum)
		{
			max_sum = cur_sum;
		}
	}
	return max_sum;
}

void Test()
{
	int data[] = {1,2,-10,4,5};
	int len = sizeof(data)/sizeof(int);
	cout << GreatestSumOfSubarrays(data, len) << endl;
}

int main() {
	Test();
	return 0;
}
