/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
         vector<int> list;
         ListNode* p=head;
        while(p!=NULL)
            {
            list.push_back(p->val);
            p=p->next;
        }
        int len = list.size();
        for(int i=0;i<len/2;i++)
            {
            int temp = list[i];
            list[i] = list[len-1-i];
            list[len-1-i] = temp;
        }
          
        return list;
    }
};