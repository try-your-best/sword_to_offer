#include <iostream>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_p_left;
    BinaryTreeNode* m_p_right;
};

void PreorderWalk(BinaryTreeNode* p_node)
{
    if(p_node != NULL)
    {
        cout << p_node->m_value << " "; // Preorder;
        PreorderWalk(p_node->m_p_left);
        PreorderWalk(p_node->m_p_right);
    }
}

//遍历树非递归的实现要关注访问的时机。
void PreorderWalkNonRecursively(BinaryTreeNode* p_node)
{
    stack<BinaryTreeNode*> node_stack;
    //set second condition in case that the right node is NULL;
    while(p_node != NULL || !node_stack.empty())
    {
        while(p_node!=NULL)
        {
            cout << p_node->m_value << " "; //Preorder;注意与最外层while循环的对应
            node_stack.push(p_node);
            p_node = p_node->m_p_left;
        }
        if(!node_stack.empty())// enter when left child is NULL;注意与最外层while循环的对应
        {
            p_node = node_stack.top();
            node_stack.pop();
            p_node = p_node->m_p_right;
        }
    }
}

void InorderWalk(BinaryTreeNode* p_node)
{
    if(p_node != NULL)
    {
        InorderWalk(p_node->m_p_left);
        cout << p_node->m_value << " "; // Inorder;
        InorderWalk(p_node->m_p_right);
    }
}

void InorderWalkNonRecursively(BinaryTreeNode* p_node)
{
    stack<BinaryTreeNode*> node_stack;
    while(p_node != NULL || !node_stack.empty())
    {
        while(p_node != NULL)
        {
            node_stack.push(p_node);
            p_node = p_node->m_p_left;
        }
        if(!node_stack.empty())
        {
            p_node = node_stack.top();
            cout << p_node->m_value << " "; //Inorder;
            node_stack.pop();
            p_node = p_node->m_p_right;
        }
    }
}

void PostorderWalk(BinaryTreeNode* p_node)
{
    if(p_node != NULL)
    {
        PostorderWalk(p_node->m_p_left);
        PostorderWalk(p_node->m_p_right);
        cout << p_node->m_value << " "; // Postorder;
    }
}

//记住第一种。这种的方法与前面先序和中序的非递归形式是一致的。
void PostorderWalkNonRecursively(BinaryTreeNode* p_node)
{
    stack<BinaryTreeNode*> node_stack;
    BinaryTreeNode* pre_visited = NULL; // 指向前一个被访问的节点
    while(p_node != NULL || !node_stack.empty()) // 栈空时结束
    {
        while(p_node != NULL)
        {
            node_stack.push(p_node);
            p_node = p_node->m_p_left; // 一直向左走直到为空
        }

        p_node = node_stack.top();
        // 当前节点的右孩子如果为空或者已经被访问，则访问当前节点
        if(p_node->m_p_right == NULL || p_node->m_p_right == pre_visited)
        {
            cout << p_node->m_value << " "; // Postorder;
            pre_visited = p_node;
            node_stack.pop();
            p_node = NULL;//注意 p_node 必须置为NULL
        }
        else
            p_node = p_node->m_p_right; // 否则访问右孩子
    }
}

void PostorderWalkNonRecursively2(BinaryTreeNode* p_node) // 后序遍历的非递归     双栈法 
{
    stack<BinaryTreeNode*> node_stack1, node_stack2;
    node_stack1.push(p_node);
    while(!node_stack1.empty())  // 栈空时结束
    {
        p_node = node_stack1.top();
        node_stack1.pop();
        node_stack2.push(p_node);
        if(p_node->m_p_left != NULL)
            node_stack1.push(p_node->m_p_left);
        if(p_node->m_p_right != NULL)
            node_stack1.push(p_node->m_p_right);
    }
    while(!node_stack2.empty())
    {
        cout << node_stack2.top()->m_value<< " ";
        node_stack2.pop();
    }
}

void Test1()
{
    BinaryTreeNode n1;
    BinaryTreeNode n2;
    BinaryTreeNode n3;
    BinaryTreeNode n4;
    n1.m_p_left = &n2;
    n1.m_p_right = &n3;
    n2.m_p_left = NULL;
    n2.m_p_right = &n4;
    n3.m_p_left = n3.m_p_right = NULL;
    n4.m_p_left = n4.m_p_right = NULL;
    n1.m_value = 1;
    n2.m_value = 2;
    n3.m_value = 3;
    n4.m_value = 4;
//    PreorderWalkNonRecursively(&n1);
//    PreorderWalk(&n1);
//    InorderWalk(&n1);
//    InorderWalkNonRecursively(&n1); 
    PostorderWalk(&n1);
    cout << endl;
    PostorderWalkNonRecursively(&n1);
    cout << endl;
    PostorderWalkNonRecursively2(&n1);
    cout << endl;
}

int main()
{
    Test1();
}
