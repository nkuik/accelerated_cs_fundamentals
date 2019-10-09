/*

Implement below the downHeap procedure for a min heap.

Unlike the video lessons which demonstrated downHeap
implemented with an array implementation, this assignment
uses an ordinary binary tree with left and right child
pointers. This ordinary binary tree might not be complete
or balanced: any node might have only one child or the other,
or both, or neither.

Suppose you are given a tree where the left and right
subtrees are min heaps, but the root node does not
maintain the min heap property. Your code should
modify the tree rooted at Node* n so it is a min heap.
(This means you need to satisfy the min heap property:
it is okay for a node's value to be equal to one or both
of its children, but the node's value must not be greater
than either of its children. You do not have to try to
balance the tree or make it a complete tree.)

Tips:
If the root node exists, and if it has a left or right
child, and if one of the children has a smaller value
than the root node, then you should swap the root node
with the smaller child to move the large value down
into the tree. (This may need to be done recursively.)
Be careful to check whether pointers are null before
dereferencing them, as always; that includes using "->"
to access a class member through a pointer. In addition,
you must be careful not to accidentally compare "left"
and "right" pointers directly if you really intend to
compare the stored values "left->value" and "right->value".

Assume that these headers have already been included
for you:

#include <iostream>
#include <string>

You have the following class Node already defined.
You cannot change this class definition, so it is
shown here in a comment for your reference only:

class Node {
public:
  int value;
  Node *left, *right;
  Node(int val = 0) { value = val; left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

This function has also previously been defined for you:

void printTreeVertical(const Node* n);

You can use it to print a verbose, vertical diagram of
a tree rooted at n. In this vertical format, a left child
is shown above a right child in the same column. If no
child exists, [null] is displayed.

*/

void printTree(Node *n) {
  if (!n) return;
  std::cout << n->value << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
}


void downHeap(Node *n) {
  if (!n) { return; }
  if (!n->right && !n->left ) { return; }
  
  std::cout << "N is: " << n->value << std::endl;
  bool go_right;
  
  if (!n->right) {
    go_right = false;
    if (n->value > n->left->value) {
      std::swap(n->value, n->left->value);
    }
  }
  else if (!n->left) {
    go_right = true;
    if (n->value > n->right->value) {
      std::swap(n->value, n->right->value);
    }
  }
  else if (n->right && n->left) {
    if (n->value > n->right->value && n->value > n->left->value) {
      
      go_right = n->right->value < n->left->value ? true : false;
    
      if (!go_right) {
        std::swap(n->value, n->left->value);
      }
      if (go_right){
        std::swap(n->value, n->right->value);
      }  
    }
    else if (n->value > n->right->value) {
      std::swap(n->value, n->right->value);
    }
    else if (n->value > n->left->value) {
      std::swap(n->value, n->left->value);
    }
    else { return; }
  }
  
  go_right ? downHeap(n->right) : downHeap(n->left);
  // printTreeVertical(n);
  // downHeap(n->right);
  // downHeap(n->left);
}

// You can also use this compact printing function for debugging.

int main() {
  Node *n = new Node(100);
  n->left = new Node(400);
  n->left->left = new Node(300);
  n->left->right = new Node(200);
  n->right = new Node(1);
  n->right->left = new Node(3);
  n->right->right = new Node(9);
  n->right->right->right = new Node(17);
  n->right->right->left = new Node(11);
  n->right->right->right->right = new Node(8);
  n->right->right->right->left = new Node(7);
  std::cout << std::endl << "Before: Vertical printout:" << std::endl;
  printTreeVertical(n);

  downHeap(n);
  
  std::cout << "After attempted sort, n is: " << n->value << std::endl;
  std::cout << "After attempted sort, n-right is: " << n->right->value << std::endl;

  std::cout << "After: Compact printout:" << std::endl;
  printTree(n);
  std::cout << std::endl << "After Vertical printout:" << std::endl;
  printTreeVertical(n);

  delete n;
  n = nullptr;

  return 0;
}
