##  Boundary Order Traversal

## Write a program for the Anti-Clockwise Boundary traversal of a binary tree.
<br>

![example](https://lh4.googleusercontent.com/I5V2oP6krQzwGUoXASv3vBVYpD_kDAMYWpjfxjbOddY08pWjgZ4nVPfc74Zg63pVUg8XI98-cB0ui9oAcr-FZmcVMqALsMHMJoOj6WZXbaCVo4xZ6d3lEGrFDwVAGHbf07P9jYju)
<br>

## Approach:

- Part 1: Left Boundary of the tree(excluding leave nodes)
- Part 2: leave nodes from left to right direction
- Part 3: Right boundary of the tree traversed in reverse direction

To print the leaf nodes, we can do a simple preorder traversal, and check if the current node is a leaf node or not. If it is a leaf node just print it.

## Code:

~~~~~~

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}
~~~~~~

## Time Complexity: O(N)
as O(H)+O(H)+O(N) approx ~O(N)

## Space Complexity: O(N)
Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).

## Reference :
check this [link](https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/)
