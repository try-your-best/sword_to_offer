#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_p_left;
    BinaryTreeNode* m_p_right;
};

int TreeDepth(BinaryTreeNode* p_root)
{
    if(p_root == NULL)
        return 0;
    int left_depth = TreeDepth(p_root->m_p_left);
    int right_depth = TreeDepth(p_root->m_p_right);
    return left_depth > right_depth ? left_depth+1 : right_depth+1;
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
    n3.m_p_left = NULL;
    n3.m_p_right = &n6;
    n4.m_p_left = n4.m_p_right = NULL;
    n5.m_p_left = &n7;
    n5.m_p_right = NULL;
    n6.m_p_left = n6.m_p_right = NULL;
    n7.m_p_left = n7.m_p_right = NULL;
    n1.m_value = 10;
    n2.m_value = 6;
    n3.m_value = 14;
    n4.m_value = 4; 
    n5.m_value = 8; 
    n6.m_value = 12; 
    n7.m_value = 16; 
    cout << TreeDepth(&n1) << endl;
}

int main()
{
    Test();
    return 0;
}
