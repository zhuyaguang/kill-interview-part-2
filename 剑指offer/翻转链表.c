//头插法
//
struct ListNode{
	int value;
	ListNode *next;
}

ListNode *ReverseList(ListNode *head)
{
	ListNode *newHead = head;
	head = head ->next;

	newHead ->next = NULL;

	while (head) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        
        return newHead;


}