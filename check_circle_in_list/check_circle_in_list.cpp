/*
 * 判断一个单向链表是否形成了环形结构。
 *思路：定义两指针，一个指针一次走一步，另外一个一次走两步，
 *如果快的指针追上慢的，则链表形成环，如果快的走到了链表末尾都没有追上，则链表无环！
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int m_val;
	ListNode *m_p_next;
	ListNode(int x):m_val(x),m_p_next(NULL){}
};

bool CheckCircleInList(ListNode *p_node)
{
	if(p_node == NULL)
	{
		return false;
	}
	ListNode dumpy(0);
	dumpy.m_p_next = p_node;
	ListNode *p_fast = &dumpy;
	ListNode *p_slow = &dumpy;
	while(p_fast != NULL && p_fast->m_p_next != NULL)
	{
		p_fast = p_fast->m_p_next;
		p_fast = p_fast->m_p_next;
		p_slow = p_slow->m_p_next;
		if(p_fast == p_slow)
		{
			return true;
		}
	}
	return false;
}

void Test()
{
	ListNode n1(1);
	ListNode n2(3);
	ListNode n3(5);
	n1.m_p_next = &n2;
	n2.m_p_next = &n3;
	n3.m_p_next = &n1;
	cout << CheckCircleInList(&n1)<<endl;
}

int main()
{
	Test();
	return 0;
}
