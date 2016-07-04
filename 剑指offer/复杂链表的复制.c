//分三步走，1.复制next节点放在原链表后面2.复制随机节点，按照原链表的顺序3.把两个链表分开

 RandomListNode* Clone(RandomListNode* pHead)
    {
    	//1
        RandomListNode* currentNode = pHead;
        while(currentNode)
        {
        	RandomListNode *node = new RandomListNode(currentNode->label);
        	node->next = currentNode->next;
        	currentNode->next = node;
        	currentNode = node->next;
        }
        //2
        currentNode = pHead;

        while(currentNode->random)
        {
        	currentNode->next->random=currentNode->random->next;
        	currentNode = currentNode->next->next;
        }

        //3
        RandomListNode* copyHead = pHead->next;

        currentNode = pHead;

        RandomListNode *tmp;

        while(currentNode->next){
        	tmp = currentNode ->next;
        	currentNode->next = tmp->next;
        	currentNode = tmp;
        }

        return copyHead;
    }
