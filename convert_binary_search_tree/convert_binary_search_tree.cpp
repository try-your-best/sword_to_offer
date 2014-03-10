#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_p_left;
    BinaryTreeNode* m_p_right;
};

void ConvertNode(BinaryTreeNode* p_node, BinaryTreeNode** p_last_node_of_list);

BinaryTreeNode* Convert(BinaryTreeNode* p_root)
{
    BinaryTreeNode* p_last_node_of_list = NULL;
    ConvertNode(p_root, &p_last_node_of_list);

    BinaryTreeNode* p_head_of_list = p_last_node_of_list;
    while(p_head_of_list != NULL && p_head_of_list->m_p_left != NULL)
        p_head_of_list = p_head_of_list->m_p_left;
    return p_head_of_list;
}

void ConvertNode(BinaryTreeNode* p_node, BinaryTreeNode** p_last_node_of_list)
{
   if(p_node == NULL)
       return;
   BinaryTreeNode* p_current = p_node;
//   BinaryTreeNode* p_last_node_of_list = NULL;
   if(p_current->m_p_left != NULL)
       ConvertNode(p_current->m_p_left, p_last_node_of_list);

   p_current->m_p_left = *p_last_node_of_list;
   if(*p_last_node_of_list != NULL)
      (*p_last_node_of_list)->m_p_right = p_current;

   *p_last_node_of_list = p_current;

   if(p_current->m_p_right != NULL)
       ConvertNode(p_current->m_p_right, p_last_node_of_list);
   
}

void PrintDoubleLinkedList(BinaryTreeNode* p_node_of_list)
{
    if(p_node_of_list == NULL)
        return;
    while(p_node_of_list->m_p_right != NULL)
    {
        cout << p_node_of_list->m_value << " ";
        p_node_of_list = p_node_of_list->m_p_right;
    } 
    cout << p_node_of_list->m_value << endl;
    while(p_node_of_list->m_p_left != NULL)
    {
        cout << p_node_of_list->m_value << " ";
        p_node_of_list = p_node_of_list->m_p_left;
    }
    cout << p_node_of_list->m_value << endl;
}

void Test()
{
    BinaryTreeNode n1;
    BinaryTreeNode n2;
    BinaryTreeNode n3;
    BinaryTreeNode n4;
    BinaryTreeNode n5;
    BinaryTreeNode n6;
    BinaryTreeNode n7;
    n1.m_p_left = &n2;
    n1.m_p_right = &n3;
    n2.m_p_left = &n4;
    n2.m_p_right = &n5;
    n3.m_p_left = &n6;
    n3.m_p_right = &n7;
    n4.m_p_left = n4.m_p_right = NULL;
    n5.m_p_left = n5.m_p_right = NULL;
    n6.m_p_left = n6.m_p_right = NULL;
    n7.m_p_left = n7.m_p_right = NULL;
    n1.m_value = 10;
    n2.m_value = 6;
    n3.m_value = 14;
    n4.m_value = 4; 
    n5.m_value = 8; 
    n6.m_value = 12; 
    n7.m_value = 16; 
    BinaryTreeNode* p_head_of_list = Convert(&n1);
//    if(p_head_of_list != NULL)
//        cout << p_head_of_list ->m_value << endl;
    PrintDoubleLinkedList(p_head_of_list);
}

void Test1()
{
    BinaryTreeNode* p_head_of_list = Convert(NULL);
    PrintDoubleLinkedList(p_head_of_list);
}

int main()
{
    Test1();
    return 0; 
}
