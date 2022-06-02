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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Using external linked list
        
        // ListNode* ans=new ListNode(0);
        // ListNode* temp=ans;
        // while(list1 !=NULL || list2!=NULL){
        //     if(list1==NULL){
        //         while(list2!=NULL){
        //             temp->next=list2;
        //             temp=temp->next;
        //             list2=list2->next;
        //         }
        //         break;
        //     }
        //     if(list2==NULL){
        //         while(list1!=NULL){
        //             temp->next=list1;
        //             temp=temp->next;
        //             list1=list1->next;
        //         }
        //         break;
        //     }
        //     if(list1->val>=list2->val){
        //         temp->next=list2;
        //         temp=temp->next;
        //         if(list2->next==NULL)
        //             list2=NULL;
        //         else
        //         list2=list2->next;
        //     }
        //     else {
        //         temp->next=list1;
        //         temp=temp->next;
        //          if(list1->next==NULL)
        //             list1=NULL;
        //         else
        //         list1=list1->next;
        //     }
        // }
        // return ans->next;
        
        // in place method
        // TC: O(N1+N2) SC: O(1) 
        
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode *temp=NULL,*res;
        if(list1->val>list2->val)
            swap(list1,list2);
        res=list1;
        while(list1!=NULL && list2!=NULL){
            temp=NULL;
            while(list1!=NULL && list1->val<=list2->val){
               temp=list1;
               list1=list1->next;
                
            }
            temp->next=list2;
            swap(list1,list2);
            
        }
       return res; 
    }
};