#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


void Permutation(char *str, int len, int start)
{
	if(str == NULL || len <= 0 || start < 0)
		return;
	if(start == len)
	{
		cout << str << endl;
		return;
	}
	for(int i = start; i < len; i++)
	{
		swap(str[start], str[i]);
		Permutation(str, len, start+1);//note: 这里是start+1,表示排列的字符串较小一个;
		swap(str[start], str[i]);
	}
}

void Permutation(char *str)//让函数接口友好！！
{
	Permutation(str, strlen(str), 0);
}

void Test()
{
	char str[] = "abc";
	Permutation(str);
}


int main() {
	Test();
	return 0;
}
