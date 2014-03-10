#include<iostream>

using namespace std;

enum Status { valid = 0, invalid};

int g_status = valid;


int StrToIntCore(const char* str, bool minus)
{
    if( *str == '\0')
        return 0;
    long long num = 0;
    while(*str != '\0')
    {
        if((*str >= '0') && (*str <= '9'))
        {
            num = num * 10 + *str - '0';
            if((!minus && (num > 0x7FFFFFFF)) || (minus && (num > 0x80000000)))
                return 0;
        }
        else
        {
            return 0;
        }
        str++; // Note to increase str!!!;
    }
    if(minus)
        num = num * -1;
    g_status = valid;
    return (int) num; 
}

int StrToInt(const char* str)
{
    g_status = invalid;
    int num = 0;
    if(str != NULL && *str != '\0')
    {
        bool minus = false;
        if(*str == '-')
        {
            minus = true;
            str++;
        }
        else if(*str == '+')
        {
            str++;
        }
        num = StrToIntCore(str, minus);
    }
    return num;
}

void Test()
{
    char str[] = "";
//    if(*str == '\0')
//        cout << "k"  << endl;
    int num = StrToInt(str);
    cout << num << endl;
    if(g_status ==  invalid)
        cout << "error" << endl;
}

void Test1()
{
    int num = 0x80000000; 
    cout << num << endl;
    char str[] = "-2147483648";
    num = StrToInt(str);
    cout << num << endl;
    if(g_status ==  invalid)
        cout << "error" << endl;
}

void Test2()
{
    int num = 0x7FFFFFFF; 
    cout << num << endl;
    char str[] = "2147483648";
    num = StrToInt(str);
    cout << num << endl;
    if(g_status == invalid)
        cout << "error" << endl;
}

int main()
{
    Test();
    return 0;
}
