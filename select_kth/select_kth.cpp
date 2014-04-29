#include <iostream>
#include<algorithm>
using namespace std;

int Partition(int data[], int low, int high)
{
    int key = data[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(data[j] <= key)
        {
            swap(data[++i], data[j]);
        }
    }
    swap(data[++i], data[high]);
    return i;
}

int SelectKth(int data[], int len, int kth)
{
	int low = 0;
	int high = len -1;
	int index = Partition(data, low, high);
	while(index != kth -1)
	{
		if(index < kth - 1)
		{
			low = index + 1;
			index = Partition(data, low, high);
		}
		else
		{
			high = index - 1;
			index = Partition(data, low, high);
		}
	}
	return data[index];
}

void Test()
{
	int data[] = {1,3,2,4,0};
	int len = sizeof(data)/sizeof(int);
	cout << SelectKth(data, len, 2) << endl;
}

int main() {
	Test();
	return 0;
}
