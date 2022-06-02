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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return true;
        
        
       ListNode *slow=head ,*fast=head;
       
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // reverse right half
        ListNode *prev=NULL , *cur=slow->next ,*nxt=NULL;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        
       slow->next=prev;
       slow=slow->next;
        
        while(slow){
            if(slow->val!=head->val)
                return false;
            slow=slow->next;
            head=head->next;
            
        }
        return true;
    }
};