/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head== NULL || k==1) return head;
      ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        ListNode *cur=head, *nxt;
        
        int c=0;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        while(c>=k){
            cur=pre->next;
            nxt=cur->next;
            
            for(int i=1;i<k;i++){
                cur->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=cur->next;
            }
            pre=cur;
            c-=k;
        }
        return dummy->next;
    }
};