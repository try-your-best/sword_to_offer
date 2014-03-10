#include <iostream>

using namespace std;

struct ListNode
{
    int m_key;
    ListNode* m_p_next;
};


ListNode* ReverseList(ListNode* p_head)
{
    ListNode* p_reverse_head = NULL;
    ListNode* p_node = p_head;
    ListNode* p_prev = NULL;
    while(p_node != NULL)
    {
        ListNode* p_next = p_node->m_p_next;
        if(p_next == NULL)
            p_reverse_head = p_node;
        p_node->m_p_next = p_prev;
        p_prev = p_node;
        p_node = p_next;
    }
    return p_reverse_head; 
}

ListNode* ReverseListRecurse(ListNode* p_node, ListNode* p_prev)
{
    if(p_node == NULL)
        return NULL;
    ListNode* p_next = p_node->m_p_next;
    p_node->m_p_next = p_prev;
    if(p_next == NULL)
        return p_node;
    else
    {
        return ReverseListRecurse(p_next, p_node);
    }
}


void Print(ListNode* p_head)
{
    while(p_head != NULL)
    {
        cout << p_head->m_key << endl;
        p_head = p_head->m_p_next;
    }
}

void Test()
{
    ListNode n1;
    ListNode n2;
    ListNode n3;
    n1.m_key = 1;
    n2.m_key = 2;
    n3.m_key = 3;
    n1.m_p_next = &n2;
    n2.m_p_next = &n3;
    n3.m_p_next = NULL; // note to initialize;
    Print(&n1);
//    Print(ReverseList(&n1));
    Print(ReverseListRecurse(NULL, NULL));
}

int main()
{
    Test();
}
