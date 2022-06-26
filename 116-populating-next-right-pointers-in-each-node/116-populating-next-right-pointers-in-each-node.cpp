/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
//         if(!root) return NULL;
        
//         queue<Node*>q;
//         q.push(root);
        
//         while(!q.empty()){
//             int sz=q.size();
            
//                 Node* temp=q.front();
//                 q.pop();
//             if(temp->left)
//                 q.push(temp->left);
//             if(temp->right)
//                 q.push(temp->right);
     
//             for(int i=1;i<sz;i++){
//                 temp->next=q.front();
//                 temp=q.front();
//                  if(temp->left)
//                 q.push(temp->left);
//             if(temp->right)
//                 q.push(temp->right);
//                 q.pop();
//             }
//             temp->next=NULL;
            
//         }
//         return root;
        
          if (root == NULL) return NULL;
    Node *pre = root;
    Node *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
        return root;
    }
    
};