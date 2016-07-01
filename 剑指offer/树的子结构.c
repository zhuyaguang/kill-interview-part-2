#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	}

bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
	if (pRoot2 == NULL)
	{
		return true;
	}

	if (pRoot1 == NULL && pRoot2 == NULL)
	{
		return false;
	}

	if (pRoot1->val == pRoot2->val)
	{
		return isSubTree(pRoot1->left,pRoot2->left) && isSubTree(pRoot1->right,pRoot2->right);
	}
	else return false;
}


//第一步寻找1中是否有2根节点一样值的点
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    		bool flag = false;

    if (pRoot2 == NULL)
	{
		return false;
	}

	if (pRoot1 == NULL && pRoot2 != NULL)
	{
		return false;
	}

	if (pRoot1->val == pRoot2->val)
	{
		//找到值一样的点后，就判断结构是不是一样
		flag = isSubTree(pRoot1,pRoot2);
	}

	if (!flag)
	{
		flag = HasSubtree(pRoot1->left,pRoot2);
	}
	if (!flag)
	{
		flag = HasSubtree(pRoot1->right,pRoot2);
	}

	return flag;
}