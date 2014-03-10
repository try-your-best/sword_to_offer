#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_p_left;
    BinaryTreeNode* m_p_right;
};

void MirrorRecursively(BinaryTreeNode* p_node)
{
    if(p_node == NULL)
        return;
    if(p_node->m_p_left == NULL && p_node->m_p_right == NULL)
        return;
    BinaryTreeNode* tmp = p_node->m_p_left;
    p_node->m_p_left = p_node->m_p_right;
    p_node->m_p_right= tmp;
    if(p_node->m_p_left != NULL) 
        MirrorRecursively(p_node->m_p_left);
    if(p_node->m_p_right != NULL)
        MirrorRecursively(p_node->m_p_right);
}
/*
由于递归的本质是编译器生成了一个函数调用的栈，因此用循环来完成同样任务时最简单的办法就是
用一个辅助栈来模拟递归。首先我们把树的头结点放入栈中。在循环中，只要栈不为空，弹出栈的栈
顶结点，交换它的左右子树。如果它有左子树，把它的左子树压入栈中；如果它有右子树，把它的右
子树压入栈中。这样在下次循环中就能交换它儿子结点的左右子树了。参考代码如下：
*/
void MirrorNonrecursively(BinaryTreeNode* p_node)
{
    if(p_node == NULL)
        return;
    stack<BinaryTreeNode*> node_stack;
    node_stack.push(p_node);
    while(! node_stack.empty())
    {
        p_node = node_stack.top();
        node_stack.pop();
        
        // swap the right and left child sub-tree
        BinaryTreeNode* tmp = p_node->m_p_left;
        p_node->m_p_left = p_node->m_p_right;
        p_node->m_p_right = tmp;
        if(p_node->m_p_right != NULL)
            node_stack.push(p_node->m_p_right);
        if(p_node->m_p_left != NULL)
            node_stack.push(p_node->m_p_left);
    }
}

void InorderWall(BinaryTreeNode* p_node)
{
    if(p_node != NULL)
    {
        InorderWall(p_node->m_p_left);
        cout << p_node->m_value << endl;
        InorderWall(p_node->m_p_right);
    }
        
}

void Test()
{
    BinaryTreeNode n1;
    BinaryTreeNode n2;
    BinaryTreeNode n3;
    n1.m_p_left = &n2;
    n1.m_p_right = &n3;
    n2.m_p_left = n2.m_p_right = NULL;
    n3.m_p_left = n3.m_p_right = NULL;
    n1.m_value = 1;
    n2.m_value = 2;
    n3.m_value = 3;
    InorderWall(&n1);
    MirrorRecursively(&n1);
    InorderWall(&n1);
}

void Test2()
{
    int a = 1, b = 2, c = 3;
    a = b = c = 0;
    cout << a << b << c << endl;
}

int main()
{
   Test(); 
}
