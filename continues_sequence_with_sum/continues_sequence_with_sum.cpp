#include <iostream>
using namespace std;

void FoundContinuousSequence(int sum)
{
	if(sum < 3)
		return;
	int small = 1;
	int big = 2;
	int cur_sum = small+big;
	int mid = (sum+1)/2;
	while(small < mid)
	{
		if(cur_sum == sum)
		{
			cout << small <<"," << big << endl;
			big++;//注意，在找到当前数字后，记得继续增大big值，寻找下一组答案！
			cur_sum+=big;
		}
		else if(cur_sum > sum)
		{
			cur_sum-=small;
			small++;
		}
		else
		{
			big++;
			cur_sum+=big;
		}
	}
}

void Test()
{
	FoundContinuousSequence(15);
}

int main() {
	Test();
	return 0;
}
