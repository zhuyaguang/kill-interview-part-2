struct ListNode{
	int value;
	ListNode *next;
}

ListNode *merge(ListNode *head1,ListNode *head2)
{
	if (head1 == NULL)
	{
		return head2;
	}

	if (head2 == NULL)
	{
		return head1;
	}
	ListNode *newHead == NULL;

	if (head1 -> value < head2 ->value)
	{
		newHead = head1;

		newHead ->next = merge(head1->next,head2);
	}else {
		newHead = head2;
		newHead ->next = merge(head2->next,head1);
	}

	return newHead;
}