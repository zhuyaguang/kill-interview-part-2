
bool IsBalanced = true;
bool IsBalanced_Solution(TreeNode* pRoot) {
		getDepth(pRoot);

		return IsBalanced;
    }

int getDepth(TreeNode* pRoot){

	if (pRoot == NULL)
	{
		return 0;
	}

	int left = getDepth(pRoot->left);

	int right = getDepth(pRoot->right);

	if (left - right < -1 || left-right > 1)
	{
		return false;
	}

	return left>right ? left+1 :right+1;

}