#include<iostream>
using namespace std;

struct ListNode
{
    int m_value;
    ListNode* m_p_next;
};

ListNode* FindKthToTail(ListNode* p_list_head, unsigned int k)
{
    if(p_list_head == NULL || k == 0)
    {
        cout << "invalid input" << endl;
        return NULL;
    }
    ListNode* p_ahead = p_list_head;
    ListNode* p_behind = p_list_head;
    unsigned int step = 0;
    while(step < k - 1 && p_ahead != NULL)
    {
        p_ahead = p_ahead->m_p_next;
        step++;
    }
    if(step < k -1)
    {
        cout << "k is too big" << endl;
        return NULL;
    }
    while(p_ahead->m_p_next != NULL)
    {
        p_ahead = p_ahead->m_p_next;
        p_behind = p_behind->m_p_next;
    }
    return p_behind; 
}

void Print(ListNode* p_head)
{
    while(p_head != NULL)
    {
        cout << p_head->m_value << endl;
        p_head = p_head->m_p_next;
    }
}

void Test1()
{ 
    ListNode n1;
    ListNode n2;
    ListNode n3;
    n1.m_value = 1;
    n2.m_value = 2;
    n3.m_value = 3;
    n1.m_p_next = &n2;
    n2.m_p_next = &n3;
    n3.m_p_next = NULL; // note to initialize;
//    Print(&n1);
    ListNode* result = FindKthToTail(NULL,-10);
    if(result == NULL)
        cout << "error" << endl;
    else cout << result->m_value << endl;
}

int main()
{
    Test1();
}
