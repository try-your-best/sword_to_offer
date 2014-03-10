#include<iostream>
#include <cstring>
using namespace std;


void Swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void Permutation(char* str, int length, int start)
{
    if(str == NULL || length < 0 || start < 0)
        return;
    if(start == length)
    {
        cout << str << endl;
        return;
    }
    for(int i = start; i < length; i++)
    {
        Swap(&str[start], &str[i]);
        Permutation(str, length, start+1); //note: 这里是start+1,表示排列的字符串较小一个;
        Swap(&str[start], &str[i]);
    }   
}

void Test()
{
     char str[] = "abc";
    //error, because "abc" is constant
    //char *str = "abc";
    Permutation(str, strlen(str), 0);
}

int main()
{
    Test();
    return 0;
}
