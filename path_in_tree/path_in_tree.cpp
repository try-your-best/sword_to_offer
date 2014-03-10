#include<vector>
#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_p_left;
    BinaryTreeNode* m_p_right;
};

void FindPath(BinaryTreeNode* p_root, int expected_sum, vector<int>& path, int current_sum)
{
    if(p_root == NULL)
        return;
    bool is_leaf = (p_root->m_p_left == NULL) && (p_root->m_p_right == NULL);
    if(is_leaf)
    {
        if(current_sum + p_root->m_value == expected_sum)
        {
            vector<int>::iterator iter = path.begin();
            for(;iter != path.end(); ++iter)
            {
                cout << *iter << " ";    
            }
            cout << p_root->m_value << " " << endl;
        }
        return; 
    }
    else
    {
        path.push_back(p_root->m_value);
        current_sum += p_root->m_value;
    }
    if(p_root->m_p_left != NULL)
        FindPath(p_root->m_p_left, expected_sum, path, current_sum);
    if(p_root->m_p_right != NULL)
        FindPath(p_root->m_p_right, expected_sum, path, current_sum);
    path.pop_back();
}

void FindPath(BinaryTreeNode* p_root, int expected_sum)
{
    if(p_root == NULL)
        return;
    vector<int> path;
    FindPath(p_root, 22, path, 0);
}


void Test()
{
    BinaryTreeNode n1;
    BinaryTreeNode n2;
    BinaryTreeNode n3;
    BinaryTreeNode n4;
    BinaryTreeNode n5;
    n1.m_p_left = &n2;
    n1.m_p_right = &n3;
    n2.m_p_left = &n4;
    n2.m_p_right = &n5;
    n3.m_p_left = n3.m_p_right = NULL;
    n4.m_p_left = n4.m_p_right = NULL;
    n5.m_p_left = n5.m_p_right = NULL;
    n1.m_value = 11;
    n2.m_value = 5;
    n3.m_value = 13;
    n4.m_value = 7; 
    n5.m_value = 6; 
    FindPath(&n1,22);
}

int main()
{
    Test();
}
