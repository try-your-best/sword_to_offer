#include <iostream>
using namespace std;

class Temp
{
public:
	Temp()
	{
		m_num++;
		m_sum+=m_num;
	}
	static int GetSum()
	{
		return m_sum;
	}
	static void Reset()
	{
		m_num = 0;
		m_sum = 0;
	}
private:
	static int m_num;
	static int m_sum;
};

int Temp::m_num = 0;
int Temp::m_sum = 0;

void Test()
{
	Temp::Reset();
	Temp * a = new Temp[0];
	delete[] a;
	a = NULL;
	cout << Temp::GetSum() << endl;
}

int main() {
	Test();
	return 0;
}
