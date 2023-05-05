
#include <iostream>
#include <stack>
#include <string>
#include <queue>

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *createTreeHelper(int *nodes, int *idx)
{
  (*idx)++;
  int data = nodes[*idx];

  if (data == -1)
    return nullptr;

  Node *newNode = new Node(data);
  newNode->left = createTreeHelper(nodes, idx);
  newNode->right = createTreeHelper(nodes, idx);

  return newNode;
}

Node *createTree(int *nodes)
{
  int idx = -1;
  return createTreeHelper(nodes, &idx);
}

// Recursive
void inOrder(Node *root)
{
  if (!root)
    return;

  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root)
{
  if (!root)
    return;

  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root)
{
  if (!root)
    return;

  postOrder(root->left);
  postOrder(root->right);
  std::cout << root->data << " ";
}

// Iterative 👍

void levelOrder(Node *root)
{
  /*
  1
  23
  4567
  */

  std::queue<Node *> q;

  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *curr = q.front();
    q.pop();

    if (curr)
    {
      std::cout << curr->data << "";

      if (curr->left)
        q.push(curr->left);
      if (curr->right)
        q.push(curr->right);
    }
    else
    {
      // Means that starting of a new level
      if (!q.empty())
      {
        std::cout << "\n";
        q.push(NULL);
      }
    }
  }
}
// void inOrderIter(Node *root)
// {

//   if (!root)
//     return;

//   std::stack<Node *> s;

//   Node *curr = root;

//   while (curr || !s.empty())
//   {
//     if (curr)
//     {
//       s.push(curr);
//       curr = curr->left;
//     }
//     else
//     {
//       curr = s.top();
//       s.pop();
//       std::cout << curr->data << " ";
//       curr = curr->right;
//     }
//   }
//   std::cout << "\n";
// }

// void preOrderIter(Node *root)
// {
//   if (!root)
//     return;

//   std::stack<Node *> s;
//   s.push(root);

//   Node *curr = nullptr;

//   while (!s.empty())
//   {

//     curr = s.top();
//     s.pop();

//     std::cout << curr->data;

//     if (curr->right)
//       s.push(curr->right);

//     if (curr->left)
//       s.push(curr->left);
//   }

//   std::cout << "\n";
// }

// void postOrderIter(Node *root)
// {

//   if (!root)
//     return;

//   std::stack<Node *> s1;
//   std::stack<Node *> s2;

//   Node *curr = root;
//   s1.push(curr);

//   while (!s1.empty())
//   {
//     curr = s1.top();
//     s1.pop();
//     s2.push(curr);

//     if (curr->left)
//       s1.push(curr->left);
//     if (curr->right)
//       s1.push(curr->right);
//   }

//   while (!s2.empty())
//   {
//     curr = s2.top();
//     s2.pop();
//     std::cout << curr->data << " ";
//   }
//   std::cout << "\n";
// }

void inOrderIter(Node *root)
{
  if (!root)
    return;

  std::stack<Node *> s;

  Node *curr = root;

  while (curr || !s.empty())
  {
    if (curr)
    {
      s.push(curr);
      curr = curr->left;
    }
    else
    {
      curr = s.top();
      s.pop();
      std::cout << curr->data << " ";
      curr = curr->right;
    }
  }
  std::cout << "\n";
}

void preOrderIter(Node *root)
{
  if (!root)
    return;
  std::stack<Node *> s;
  s.push(root);
  Node *curr = nullptr;

  while (!s.empty())
  {
    curr = s.top();
    s.pop();
    std::cout << curr->data << " ";

    if (curr->right)
      s.push(curr->right);
    if (curr->left)
      s.push(curr->left);
  }
  std::cout << "\n";
}

void postOrderIter(Node *root)
{
  std::stack<Node *> s1;
  std::stack<Node *> s2;

  Node *curr = root;
  s1.push(curr);

  while (!s1.empty())
  {
    curr = s1.top();
    s1.pop();
    s2.push(curr);

    if (curr->left)
      s1.push(curr->left);
    if (curr->right)
      s1.push(curr->right);
  }

  while (!s2.empty())
  {
    curr = s2.top();
    s2.pop();
    std::cout << curr->data << " ";
  }
  std::cout << "\n";
}

/*
      1
   /    \
  2      3
 /  \  /  \
4   5  6   7


*/

int getSumOfAllNodes(Node *root)
{
  if (!root)
    return 0;

  return root->data + getSumOfAllNodes(root->left) + getSumOfAllNodes(root->right);
}

int getTreeHeight(Node *root)
{
  if (!root)
    return 0;

  return std::max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
}

void getTreeInfo(Node *root, int *height, int *diameter)
{
  if (!root)
    return;

  int leftHeight = 0;
  int rightHeight = 0;

  getTreeInfo(root->left, &leftHeight, diameter);
  getTreeInfo(root->right, &rightHeight, diameter);

  *height = std::max(leftHeight, rightHeight) + 1;
  *diameter = std::max(*diameter, leftHeight + rightHeight);
}

struct TreeInfo
{
  int height;
  int diameter;

  TreeInfo(int height, int diameter) : height(height), diameter(diameter) {}
};

TreeInfo getTreeInfo(Node *root)
{
  if (!root)
    return TreeInfo(0, 0);

  TreeInfo left = getTreeInfo(root->left);
  TreeInfo right = getTreeInfo(root->right);

  int height = std::max(left.height, right.height) + 1;

  int diameter = std::max(left.height + right.height, height);

  return TreeInfo(height, diameter);
}

void printTree(Node *root, int indent = 0, char edgeChar = ' ')
{
  if (!root)
    return;

  int INDENT_SIZE = 4;

  printTree(root->right, indent + INDENT_SIZE, '/');

  for (int i = 0; i < indent; i++)
    std::cout << " ";

  std::cout << edgeChar << "--" << root->data << "\n";

  printTree(root->left, indent + INDENT_SIZE, '\\');
}

bool isIdentical(Node *n1, Node *n2)
{
  if (!n1 && !n2)
    return true;
  if (!n1 || !n2)
    return false;

  return (n1->data == n2->data) && isIdentical(n1->left, n2->left) && isIdentical(n1->right, n2->right);
}

bool isSubtree(Node *root, Node *subtree)
{
  if (!subtree)
    return true;

  if (!root)
    return false;

  if (root->data == subtree->data && isIdentical(root, subtree))
    return true;

  return isSubtree(root->left, subtree) || isSubtree(root->right, subtree);
}

int main(int argc, char const *argv[])
{
  /* code */

  // int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
  int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, 8, -1, -1, 9, -1, -1};
  int nodes2[] = {7, 8, -1, -1, 9, -1, -1};
  Node *root = createTree(nodes);

  // Reset the idx i am lazy to do this
  Node *subtree = createTree(nodes2);
  // std::cout << root->data << std::endl;

  // Traversals Recursive
  inOrder(root);
  std::cout << "\n";
  preOrder(root);
  std::cout << "\n";
  postOrder(root);
  std::cout << "\n\n";

  levelOrder(root);
  std::cout << "\n\n";

  // ---
  inOrderIter(root);
  preOrderIter(root);
  postOrderIter(root);

  int treeHeight = 0;
  int treeDiameter = 0;

  TreeInfo info = getTreeInfo(root);
  std::cout << "The Sum of all nodes in the tree is: " << getSumOfAllNodes(root) << std::endl;
  // std::cout << "The Height Of the Tree is: " << getTreeHeight(root) << std::endl;

  getTreeInfo(root, &treeHeight, &treeDiameter);
  std::cout << "The Height Of the Tree is: " << info.height << std::endl;
  std::cout << "The Diameter Of the Tree is: " << info.diameter << std::endl;

  std::cout << "\n\n";
  printTree(root, 0, '|');
  std::cout << "\n\n\n";

  std::cout << "\n\n";
  printTree(subtree, 0, '|');
  std::cout << "\n\n\n";

  bool isASubtree = isSubtree(root, subtree);
  (isASubtree) ? std::cout << "The Given Tree is a subtree of the root" : std::cout << "The Given Tree not a subtree of the root!!";

  return 0;
}
