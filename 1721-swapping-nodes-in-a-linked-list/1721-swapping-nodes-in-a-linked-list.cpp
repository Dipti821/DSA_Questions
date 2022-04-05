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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left=head, *right=head , *curr=head;
        int c=1;
        while(curr!=NULL){
            if(c<k){
                left=left->next;
            }
            if(c>k){
                right=right->next;
            }
            c++;
            curr=curr->next;
        }
        int temp=right->val;
        right->val=left->val;
        left->val=temp;
        
        return head;
    }
};