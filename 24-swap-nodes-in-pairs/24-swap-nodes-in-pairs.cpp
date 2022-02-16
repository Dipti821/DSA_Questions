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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp,*p,*q;
        p=head;
        if(p==NULL || p->next==NULL)
            return p;
        ListNode* new_head=p->next;
        while(true){
            q=p->next;
            temp=q->next;
            q->next=p;
            if(temp==NULL){
             p->next=NULL;
             break;
            }
            if(temp->next==NULL){
             p->next=temp;
             break;
            }
            
            p->next=temp->next;
            p=temp;
        }
        return new_head;
        
    }
};