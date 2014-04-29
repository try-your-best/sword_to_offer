/*
 *求链表的中间节点
 *思路：定义两指针，一个指针一次走一步，另外一个一次走两步，
 *当快的指针到达链表结尾时，慢的指针正好到链表的中间！
 *
 */

#include <iostream>
using namespace std;

struct ListNode
{
	int m_val;
	ListNode *m_p_next;
	ListNode(int x):m_val(x),m_p_next(NULL){}
};

ListNode *FindMidOfList(ListNode *p_node)
{
	ListNode dumpy(0);//借助虚拟头节点，简化处理
	dumpy.m_p_next = p_node;
	ListNode *p_fast = &dumpy;
	ListNode *p_slow = &dumpy;
	while(p_fast != NULL && p_fast->m_p_next != NULL)
	{
		p_fast = p_fast->m_p_next;
		p_fast = p_fast->m_p_next;
		p_slow = p_slow->m_p_next;
	}
	return p_slow;
}

void Test()
{
	ListNode n1(1);
	ListNode n2(3);
	ListNode n3(5);
	ListNode n4(7);
	ListNode n5(9);
	n1.m_p_next = &n2;
	n2.m_p_next = &n3;
	n3.m_p_next = &n4;
	n4.m_p_next = &n5;
	ListNode *p_select = FindMidOfList(&n1);
	if(p_select != NULL)
	{
		cout << p_select->m_val << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}

int main() {
	Test();
	return 0;
}
