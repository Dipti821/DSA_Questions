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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || k==0)
            return head;
        ListNode *temp=head;
        int c=1;
        while(temp->next){
            c++;
            temp=temp->next;
        }
    k=k%c;
        int rem=c-k;
        
        temp->next=head;
    
        temp=head;
        for(int i=1;i<rem;i++){
         temp=temp->next;   
        }
        
         ListNode *new_head=temp->next;
    temp->next=NULL;
              return new_head;
              
        
    }
};