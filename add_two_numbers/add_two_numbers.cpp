#include<iostream>
using namespace std;

int Add(int num1, int num2)
{
    int sum = 0;
    int carry = 0;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }while(num2 != 0);
    return sum;
}

void Test()
{
    cout << Add(0, 1) << endl;
}

int main()
{
    Test();
    return 0;
}
