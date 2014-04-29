#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum = 0, carry = 0;
	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	}
	while(num2 != 0);
	return num1;
}

void Test()
{
	cout << Add(1000,200) << endl;
}


int main() {
	Test();
	return 0;
}
