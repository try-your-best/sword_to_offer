#include <iostream>
using namespace std;

struct ListNode
{
	int m_val;
	ListNode *m_p_next;
	ListNode(int x):m_val(x),m_p_next(NULL){}
};

ListNode *FindKthToTail(ListNode *p_list_head, unsigned int k)
{
	if(p_list_head == NULL || k == 0)
	{
		return NULL;
	}
	ListNode *p_ahead = p_list_head;
	for(unsigned int i = 0; i < k-1; i++)
	{
		p_ahead = p_ahead->m_p_next;
		if(p_ahead == NULL)
		{
			return NULL;
		}
	}
	ListNode *p_behind = p_list_head;
	while(p_ahead->m_p_next != NULL)
	{
		p_ahead = p_ahead->m_p_next;
		p_behind = p_behind->m_p_next;
	}
	return p_behind;
}

void Test()
{
	ListNode n1(1);
	ListNode n2(3);
	ListNode n3(5);
	n1.m_p_next = &n2;
	n2.m_p_next = &n3;
	ListNode *p_select = FindKthToTail(&n1, 2);
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
