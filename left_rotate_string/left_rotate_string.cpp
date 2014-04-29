#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void Reverse(char *p_begin, char *p_end)
{
	if(p_begin == NULL || p_end == NULL)
		return;
	while(p_begin < p_end)
	{
		swap(*p_begin, *p_end);
		p_begin++;
		p_end--;
	}
}

char *LeftRotateString(char *p_str, int n)
{
	if(p_str == NULL)
		return NULL;
	int len = static_cast<int>(strlen(p_str));
	if(n <= 0 || n >= len)
		return p_str;
	char *p_first_start = p_str;
	char *p_first_end = p_str+n-1;
	char *p_second_start = p_str+n;
	char *p_second_end = p_str+len-1;
	//翻转前n个字符
	Reverse(p_first_start, p_first_end);
	//翻转后面的字符
	Reverse(p_second_start, p_second_end);
	//翻转整个字符
	Reverse(p_first_start, p_second_end);
	return p_str;
}

void Test()
{
	char str[] = "abcdefg";
	cout << LeftRotateString(str,2) << endl;
}

int main() {
	Test();
	return 0;
}
