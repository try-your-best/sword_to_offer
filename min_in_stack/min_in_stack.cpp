#include <iostream>
#include <stack>
#include <assert.h>     /* assert */
using namespace std;

template <typename T> class StackWithMin
{
public:
	StackWithMin(){}
	~StackWithMin(){}
	void Push(const T&);
	void Pop();
	const T& Min();

private:
	stack<T> m_data;
	stack<T> m_min;
};

template <typename T> void StackWithMin<T>::Push(const T& value)
{
	m_data.push(value);
	if(m_min.empty() || m_min.top() > value)
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

template <typename T> void StackWithMin<T>::Pop()
{
	assert(!m_data.empty() && !m_min.empty());
	m_data.pop();
	m_min.pop();
}

template <typename T> const T& StackWithMin<T>::Min()
{
	assert(!m_data.empty() && !m_min.empty());
	return m_min.top();
}

void Test()
{
	StackWithMin<int> my_stack;
	my_stack.Push(10);
	my_stack.Push(3);
	my_stack.Push(5);
	cout << my_stack.Min() << endl;
}

int main() {
	Test();
	return 0;
}
