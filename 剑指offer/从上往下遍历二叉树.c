//借助一个队列，先将头节点放进去 把节点值放到数组，出队列。再将节点左右节点压入队列。


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	}

vector<int> PrintFromTopToBottom(TreeNode *root) {

	queue<TreeNode*> queue;
	vector<int> r;
	q.push(root);

	while(!q.empty()){
		TreeNode *node = q.frount();
		q.pop();
		

		if (!node)
		{
			continue;
		}

		r.push_back(node->value);
		q.push(node->left);
		q.push(node->right);

	}

	return r;

    }