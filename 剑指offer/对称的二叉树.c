bool isSymmetrical(TreeNode* pRoot)
    {
    	if (pRoot == NULL)
    	{
    		return true;
    	}

    	return f(pRoot->left,pRoot->right);
    }


bool f(TreeNode* p1,TreeNode* p2)
{
	if (p1 == NULL && p2 == NULL)
	{
		return true;
	}

	if (p1 != NULL && p2 != NULL)
	{
			return p1->val==p2->val && f(p1->left,p1->right) && f(p2->left,p2->right);
	}

	return false;
}