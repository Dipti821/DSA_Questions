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
    // Merge two sorted list (save as the leetcode Question 54: Merge Two Sorted Lists)
    ListNode* sortedMerge(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(0);
        ListNode* current = res;
        while (true){
            if (!l1){
                current->next = l2;
                break;
            }
            if (!l2){
                current->next = l1;
                break;
            }
            if (l1->val < l2->val){
                current->next = l1;
                l1 = l1->next;
            }else{
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        return res->next;
    }

    // Split a list into two parts, using slow/fast pointers
    void split(ListNode* head, ListNode** aRef, ListNode** bRef){
        ListNode* slow;
        ListNode* fast;
        if (head==NULL || head->next==NULL){
            *aRef = head;
            *bRef = NULL;
        }else{
            slow = head;
            fast = head;
            while (fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                if (fast==NULL){break;} // this is important
                slow = slow->next;
            }
            *aRef = head;
            *bRef = slow->next;
            slow->next=NULL;
        }
    }

    // MergeSort LinkedList
    void mergeSort(ListNode** headRef){
        ListNode* head = *headRef;
        ListNode* a;
        ListNode* b;
        
        if (head==NULL || head->next==NULL){
            return;
        }
        
        split(head,&a,&b);   //split the list
        
        mergeSort(&a);       //sort the first part
        mergeSort(&b);       //sort the second part    
        
        *headRef = sortedMerge(a,b);    // merge two sorted part
    }

    //main function
    ListNode *sortList(ListNode *head) {
        mergeSort(&head);
        return head;
    }
};