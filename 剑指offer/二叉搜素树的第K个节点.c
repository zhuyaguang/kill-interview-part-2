TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if (pRoot == NULL)
        {
        	return NULL;
        }

        if (pRoot->left != NULL)
        {
        	TreeNode* p = KthNode(pRoot->left,k);
        	if (p != NULL)
        	{
        		return p;
        	}
        }

        if (k == 1)
        {
        	return pRoot;
        }else{
        	k--;
        }

        if (pRoot->right != NULL)
        {
        	TreeNode* p = KthNode(pRoot->right,k);
        	if (p != NULL)
        	{
        		return p;
        	}
        }
        return NULL;
    }