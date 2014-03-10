#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <deque>
using namespace std;
/*两个队列模拟一个堆栈*/
/*队列A、B
入栈：将元素依次压入到非空的队列，第一个元素压倒对列A
出栈：把队列A的前n-1个元素倒到队列B，把第n个元素去掉。此时数据在B中，下次操作，则对B操作。
栈顶：把队列A的前n-1个元素倒到队列B，把第n个元素作为栈顶*/
template <typename T>
class MyStack
{
public:
        //入栈，第一个元素进到队列deque1，以后每个元素进到非空的队列
        void  push(T element)
        {
                if (deque1.empty() && deque2.empty())
                {
                        deque1.push_back(element);
                }
                else if (!deque1.empty() && deque2.empty())
                {
                        deque1.push_back(element);
                }
                else if (deque1.empty() && !deque2.empty())
                {
                        deque2.push_back(element);
                }
        }
        //出栈，将非空队列的前n-1个元素转移到另一个空的队列，删除非空队列的第n个元素
        void pop()
        {
                if (!deque1.empty())
                {
                        int size = deque1.size();
                        for (int i=0; i<size-1; i++)
                        {
                                deque2.push_back(deque1.front());
                                deque1.pop_front();
                        }
                        deque1.pop_front();
                }
                else
                {
                        int size = deque2.size();
                        for (int i=0; i<size-1; i++)
                        {
                                deque1.push_back(deque2.front());
                                deque2.pop_front();
                        }
                        deque2.pop_front();
                }
        }
        //栈顶元素，将非空队列的前n-1个元素转移到另一个空的队列，将非空队列的第n个元素返回
        T top()
        {
                if (!deque1.empty())
                {
                        int size = deque1.size();
                        for (int i=0; i<size-1; i++)
                        {
                                deque2.push_back(deque1.front());
                                deque1.pop_front();
                        }
                        T temp = deque1.front();
                        deque1.pop_front();
                        deque2.push_back(temp);
                        return temp;
                }
                else
                {
                        int size = deque2.size();
                        for (int i=0; i<size-1; i++)
                        {
                                deque1.push_back(deque2.front());
                                deque2.pop_front();
                        }
                        T temp = deque2.front();
                        deque2.pop_front();
                        deque1.push_back(temp);
                        return temp;
                }
        }
        //栈是否为空
        bool empty()
        {
                return (deque1.empty()&&deque2.empty());
        }
private:
        deque<T> deque1;
        deque<T> deque2;
};
int main(int argc, char *argv[])
{
        MyStack<int> my;
        for (int i=0; i<10; i++)
        {
                my.push(i);
        }
        while (!my.empty())
        {
                cout<<my.top()<<" ";
                my.pop();
        }
        cout<<endl;
}

