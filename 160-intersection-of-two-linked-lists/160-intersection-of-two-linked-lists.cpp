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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map< ListNode* ,int>m;
        // while(headA){
        //     m[headA]++;
        //     headA=headA->next;
        // }
        // while(headB){
        //     if(m.find(headB)!=m.end())
        //         return headB;
        //     headB=headB->next;
        // }
        // return NULL;
        
        
        if(headA==NULL || headB == NULL) return NULL;
        ListNode *a=headA ,*b=headB;
        while(a!=b){
            a=(a==NULL)?headB:a->next;
            b=(b==NULL)?headA: b->next;
            
        }
        return a;
    }
};