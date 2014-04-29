#include <iostream>
#include <cstdlib>
using namespace std;

struct TreeNode
{
	int m_val;
	TreeNode *m_p_left;
	TreeNode *m_p_right;
	TreeNode(int x):m_val(x),m_p_left(NULL),m_p_right(NULL){}
};

bool IsBalancedBinaryTree(TreeNode *p_node, int &height)
{
	if(p_node == NULL)
	{
		height = -1;
		return true;
	}
	int left_height = 0;
	int right_height = 0;
	if(IsBalancedBinaryTree(p_node->m_p_left, left_height)
			&& IsBalancedBinaryTree(p_node->m_p_right, right_height))
	{
		if(abs(left_height - right_height) <= 1)
		{
			height = left_height > right_height ? left_height + 1 : right_height+1;
			return true;
		}
	}
	return false;
}

void Test()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	n1.m_p_left = &n2;
	n2.m_p_right = &n3;
	int height = 0;
	cout << IsBalancedBinaryTree(&n1, height) << endl;
	cout << height << endl;
}


int main() {
	Test();
	return 0;
}
