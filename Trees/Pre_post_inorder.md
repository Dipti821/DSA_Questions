 
 ## Write a program to print Preorder Inorder Postorder Traversals in one Traversal
 <br>
 
 ![Example](https://lh5.googleusercontent.com/63bUUZdT3TPXbTrShHVMGycwVhcQ5Xgww21UqCI8dlQAQa_C8zCyU0GGPoI-5C-Ejt1RbAmlPqwf_-d5DdHo_DLR4I3Yb2Et9bTb9KlWvuk5hGF2nqUVFmOg4W94q_rJmqm0VVFK)
 <br>
 
 ### Approach:
 
 We will use a stack DS and push a pair<val,num> to it. Where val is value of root node and num is the visit to a node.
 
 ### Case 1: When num==1
 
 means visiting node for first time
 
 add to preorder
 
 push same value with increase num i.e num=2
 
 push left child with num=1
 
 ### Case 2: When num==2
 
 means visiting node for second time
 
 add to inorder
 
 push same value with increase num i.e num=3
 
 push right child with num=1
 
 ### Case 3: When num==3
 
 means visiting node for third time
 
 add to postorder
 
 
 ## Code:
 
 ~~~~~~
 
 #include <bits/stdc++.h>

 using namespace std;
  
 struct node {
  int data;
  struct node * left, * right;
};

void allTraversal(node * root, vector < int > & pre, vector < int > & in , vector < int > & post) {
  stack < pair < node * , int >> st;
  st.push({root, 1});
  if (root == NULL) return;

  while (!st.empty()) {
    auto it = st.top();
    st.pop();

    // this is part of pre
    // increment 1 to 2 
    // push the left side of the tree
    if (it.second == 1) {
      pre.push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> left != NULL) {
        st.push({ it.first -> left,1});
      }
    }

    // this is a part of in 
    // increment 2 to 3 
    // push right 
    else if (it.second == 2) {
      in .push_back(it.first -> data);
      it.second++;
      st.push(it);

      if (it.first -> right != NULL) {
        st.push({it.first -> right, 1});
      }
    }
    // don't push it back again 
    else {
      post.push_back(it.first -> data);
    }
  }
}
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right = newNode(3);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  vector < int > pre, in , post;
  allTraversal(root, pre, in , post);

  cout << "The preorder Traversal is : ";
  for (auto nodeVal: pre) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The inorder Traversal is : ";
  for (auto nodeVal: in ) {
    cout << nodeVal << " ";
  }
  cout << endl;
  cout << "The postorder Traversal is : ";
  for (auto nodeVal: post) {
    cout << nodeVal << " ";
  }
  cout << endl;

  return 0;
}

~~~~~~

## OUTPUT:

The preorder Traversal is: 1 2 4 5 3 6 7

The inorder Traversal is: 4 2 5 1 6 3 7

The postorder Traversal is: 4 5 2 6 7 3 1

## Time Complexity: O(3*N) i.e O(N)
Since we are visiting each node thrice

## Space Complexity: O(4*N) i.e O(N)
three lists and a stack
 
### Article reference:

Go to this [link](https://takeuforward.org/data-structure/preorder-inorder-postorder-traversals-in-one-traversal/)


