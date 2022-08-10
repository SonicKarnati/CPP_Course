#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

/*
The height of a node is the number of edges in
its longest chain of descendants.

Implement computeHeight to compute the height
of the subtree rooted at the node n. Note that
this function does not return a value. You should
store the calculated height in that node's own
height member variable. Your function should also
do the same for EVERY node in the subtree rooted
at the current node. (This naturally lends itself
to a recursive solution!)

Assume that the following includes have already been
provided. You should not need any other includes
than these.

You have also the following class Node already defined.
You cannot change this class definition, so it is
shown here in a comment for your reference only:

*/
class Node {
public:
  int height; // to be set by computeHeight()
  Node *left, *right;
  Node() { height = -1; left = right = nullptr; }
  ~Node() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
  }
};

int countChildren(Node *n) {
  int h = 0, hLeft = 0, hRight = 0;

  // Calc the # of Children on left and right recursively
  if (n->left) {
    hLeft++;
    std::cout << "Found a child on the left" << std::endl;
    hLeft += countChildren(n->left);
  }
  if (n->right) {
    hLeft++;
    std::cout << "Found a child on the right" << std::endl;
    hLeft += countChildren(n->right);
  }

  // Height of tree = Longest leg
  // Compare height of right and left and set h to whatever is greater
  std::cout << "Right Leg:" << hRight << " VS Left Leg:" << hLeft << std::endl;
  if (hRight > hLeft) {
    h = hRight;
  }
  if (hLeft > hRight) {
    h = hLeft;
  }

  return h;
}

void computeHeight(Node *n) {
  Node *current, *previous;
  current = n;

  current->height = countChildren(n);
}

// This function prints the tree in a nested linear format.
void printTree(const Node *n) {
  if (!n) return;
  std::cout << n->height << "(";
  printTree(n->left);
  std::cout << ")(";
  printTree(n->right);
  std::cout << ")";
}

// The printTreeVertical function gives you a verbose,
// vertical printout of the tree, where the leftmost nodes
// are displayed highest. This function has already been
// defined in some hidden code.
// It has this function prototype: void printTreeVertical(const Node* n);

// This main() function is for your personal testing with
// the Run button. When you're ready, click Submit to have
// your work tested and graded.
int main() {
  Node *n = new Node();
  n->left = new Node();
  n->right = new Node();
  n->right->left = new Node();
  n->right->right = new Node();
  n->right->right->right = new Node();

  computeHeight(n);

//   printTree(n);
  std::cout << std::endl << std::endl;
//   printTreeVertical(n);
  
  // The Node destructor will recursively
  // delete its children nodes.
  delete n;
  n = nullptr;

  return 0;
}
