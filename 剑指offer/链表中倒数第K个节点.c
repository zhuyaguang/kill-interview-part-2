struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }


ListNode *FindK(ListNode *head,unsigned int k)
{
	if (head == NULL || k == 0)
	{
		return NULL;
	}

	ListNode *Node = head;
	ListNode *pHeadNode = head;
	ListNode *pFollowNode = head;
	int len ;
	while(pNode)
	{
		len++;
		pNode->next;
	}
	if (k>len)
	{
		return NULL;
	}

	for (int i = 0; i < k-1; ++i)
	{
		if (pHeadNode->next != NULL)
		{
			pHeadNode = pHeadNode->next;
		}
		
	}

	while(pHeadNode->next)
	{
		pHeadNode = pHeadNode->next;
		pFollowNode = pFollowNode->next;
	}

	return pFollowNode;
}