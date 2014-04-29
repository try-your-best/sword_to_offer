//============================================================================
// Name        : reverse_word.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

void Reverse(char *p_begin, char* p_end)
{
	if(p_begin == NULL || p_end == NULL)
	{
		return;
	}
	while(p_begin < p_end)
	{
		swap(*p_begin, *p_end);
		p_begin++;
		p_end--;
	}
}

void ReverseSentence(char *p_data)
{
	if(p_data == NULL)
		return;
	char *p_begin = p_data;
	char *p_end = p_data;
	while(*p_end != '\0')
	{
		p_end++;
	}
	p_end--;
	//翻转整个句子
	Reverse(p_begin, p_end);
	//p_end = p_data;
	//翻转句子中的每个单词
	while(*p_begin != '\0') //注意，不要写成 p_begin != '\0'
	{
		while(*p_begin != '\0' && *p_begin == ' ')
		{
			p_begin++;
		}
		p_end = p_begin;
		while(*p_end != '\0' && *p_end !=' ')
		{
			p_end++;
		}
		p_end--;
		Reverse(p_begin, p_end);
		p_end++;
		p_begin = p_end;
	}
}


int main() {
	char str[] = "  Hello World  ";
	cout <<str<<endl;
	ReverseSentence(str);
	cout << str << endl;
	return 0;
}
