#include<iostream>

using namespace std;

struct ListNode
{
    int m_value;
    ListNode* m_p_next;
};

ListNode* Merge(ListNode* p_node1, ListNode* p_node2)
{
    if(p_node1 == NULL)
        return p_node2;
    else if(p_node2 == NULL)
        return p_node1;
    ListNode* p_merged_head = NULL;
    if(p_node1->m_value >= p_node2->m_value)
    {
        p_merged_head = p_node1;
        p_merged_head->m_p_next = Merge(p_node1->m_p_next, p_node2);
    }
    else
    {
        p_merged_head = p_node2;
        p_merged_head->m_p_next = Merge(p_node1, p_node2->m_p_next);
    }
    return p_merged_head;
}

ListNode* MergeNonRecursively(ListNode* p_node1, ListNode* p_node2)
{
    if(p_node1 == NULL)
        return p_node2;
    else if(p_node2 == NULL)
        return p_node1;
    //处理合并链表的头部
    ListNode* p_merged_head = NULL;
    if(p_node1->m_value >= p_node1->m_value)
    {
        p_merged_head = p_node1;
        p_node1 = p_node1->m_p_next;
    }
    else
    {
        p_merged_head = p_node2;
        p_node2 = p_node2->m_p_next;
    }

    ListNode* p_current_node = p_merged_head;
    while(p_node1 != NULL && p_node2 != NULL)
    {
        if(p_node1->m_value >= p_node2->m_value)
        {
            p_current_node->m_p_next = p_node1;
            p_node1 = p_node1->m_p_next;
        }
        else
        {
            p_current_node->m_p_next = p_node2;
            p_node2 = p_node2->m_p_next;
        }
            p_current_node = p_current_node->m_p_next;
    }
    //处理合并链表的尾部
    if(p_node1 != NULL)
        p_current_node->m_p_next = p_node1;
    else if(p_node2 != NULL)
        p_current_node->m_p_next = p_node2;
    
    return p_merged_head;
}

void PrintList(ListNode* p_head)
{
    while(p_head != NULL)
    {
        cout << p_head->m_value << " ";
        p_head = p_head->m_p_next;
    }
    cout << endl;
}

void Test()
{
    ListNode n1;
    ListNode n2;
    n1.m_p_next = &n2;
    n2.m_p_next = NULL;
    n1.m_value = 3;
    n2.m_value = 1;

    ListNode n3;
    n3.m_p_next = NULL;
    n3.m_value = -2;
    //ListNode* p_merged_head = Merge(&n1, &n3);
    ListNode* p_merged_head = MergeNonRecursively(&n1, &n3);
    PrintList(p_merged_head);
}

int main()
{
    Test();
    return 0;
}
