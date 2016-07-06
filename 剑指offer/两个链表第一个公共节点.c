//牛客网一位大神的解法，真心6
//用两个指针扫描”两个链表“，最终两个指针到达 null 或者到达公共结点。
 ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode *p1;
        ListNode *p2;
        while(p1 != p2){
        	p1 = (p1 == NULL ? pHead2 :p1->next);
        	p2 = (p2 == NULL ? pHead1 :p2->next);
        }

        return p1;
    }



//常规解法
/*
找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
（因为2个链表用公共的尾部）
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = findListLenth(pHead1);
        int len2 = findListLenth(pHead2);
        if(len1 > len2){
            pHead1 = walkStep(pHead1,len1 - len2);
        }else{
            pHead2 = walkStep(pHead2,len2 - len1);
        }
        while(pHead1 != NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
     
    int findListLenth(ListNode *pHead1){
        if(pHead1 == NULL) return 0;
        int sum = 1;
        while(pHead1 = pHead1->next) sum++;
        return sum;
    }
     
    ListNode* walkStep(ListNode *pHead1, int step){
        while(step--){
            pHead1 = pHead1->next;
        }
        return pHead1;
    }
};