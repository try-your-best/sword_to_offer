//============================================================================
// Name        : sequence_of_bst.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool VerifySequenceOfBST(int *sequence, int len)
{
	if(sequence == NULL && len <= 0)
		return false;
	int root = sequence[len-1];
	int i = 0;
	for(; i < len -1; i++)
	{
		if(sequence[i] > root)
			break;
	}
	int j = i;
	for(; j < len -1; j++)
	{
		if(sequence[j] < root)
			return false;//注意，检查是否符合要求！
	}
	bool left = true;
	if(i>0)//判断左子树是不是二叉搜索树！
	{
		left = VerifySequenceOfBST(sequence, i);
	}
	bool right = true;
	//if(j-i > 0)
	if(i < len-1)//判断右子树是不是二叉搜索树！
	{
		right = VerifySequenceOfBST(sequence+i, j-i);
	}
	return (left && right);
}


void Test()
{
	int a[] = {5,7,6,9,11,10,8};
	int len = sizeof(a)/sizeof(int);
	cout << VerifySequenceOfBST(a, len) << endl;
}

int main() {
	Test();
	return 0;
}
