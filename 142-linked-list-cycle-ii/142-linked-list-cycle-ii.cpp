/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        // Method1: hashing
        
        // Method 2: tortoise method
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode *slow=head ,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                break;
        }
        if(slow!=fast)
            return NULL;
        if(slow==head){
            return head;
        }
        else{
            slow=head;
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow->next;
            
        }
    }
};