//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
//注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
  TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
        {
        	return NULL;
        }

        if (pNode->right != NULL)
        {
        	pNode = pNode->right;

        	while(pNode->left != NULL)
        	{
        		pNode = pNode->left;
        	}

        	return pNode;
        }

        while(p->next != NULL){
        	if (pNode == pNode->next->left)
        	{
        		return pNode->next;
        	}

        	pNode = pNode->next;
        }

        return NULL;
    }