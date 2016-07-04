vector<vector<int>> allRes;
vector<int> tmp;

void  dfsFind(TreeNode *node,int left){
	temp.push_back(node->value);
	if (left-node->value == 0 && node->left == NULL && node->right == NULL)
	{
		allRes.push_back(tmp);
	}else {
		if (node->left != NULL)
		{
			dfsFind(node->left,left-node->value);
		}

		if (node->right != NULL)
		{
			dfsFind(node->right,left-node->value);
		}
	}
}

 vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
 				if (root)
 				{
 					dfsFind(root,expectNumber);
 				}

 				return allRes;
    }