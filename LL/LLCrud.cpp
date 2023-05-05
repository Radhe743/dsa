#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;

  ListNode(int val) : val(val), next(nullptr) {}
};

std::ostream &operator<<(std::ostream &out, ListNode *node)
{
  ListNode *temp = node;

  out << "[";
  while (temp || temp)
  {
    out << temp->val << ((temp->next) ? ", " : "]\n");

    temp = temp->next;
  }

  return out;
};

void insetIntoBeginning(ListNode **head, int data)
{
  ListNode *newNode = new ListNode(data);
  if (!(*head))
  {
    *head = newNode;
    return;
  }

  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(ListNode **head, int data)
{
  ListNode *newNode = new ListNode(data);
  if (!(*head))
  {
    *head = newNode;
    return;
  }

  ListNode *temp = *head;

  while (temp->next)
    temp = temp->next;

  temp->next = newNode;
}

void insetAtPos(ListNode **head, int pos, int data)
{
  ListNode *newNode = new ListNode(data);
  if (!*head)
  {
    *head = newNode;
    return;
  }

  if (pos == 0)
  {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  ListNode *temp = *head;
  while (pos - 1 > 0 && temp->next)
  {
    temp = temp->next;
    pos--;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void insertAfterNode(ListNode **head, ListNode *afterNode, int data)
{

  if (!afterNode || !head)
    return;

  ListNode *newNode = new ListNode(data);

  if (afterNode == *head)
  {
    if ((*head)->next)
    {
      newNode->next = (*head)->next;
    }
    (*head)->next = newNode;
    return;
  }

  ListNode *temp = *head;
  // [ 1 2 4 (11) -> 5 6 ]
  while (temp != afterNode)
  {
    temp = temp->next;
  }
  newNode->next = afterNode->next;
  temp->next = newNode;
}

void reverseLLIter(ListNode **head)
{

  if (!head)
    return;

  ListNode *curr = *head;
  ListNode *prev = nullptr, *next = nullptr;

  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  *head = prev;
}
ListNode *reverseLLRecur(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *nextItem = head->next;
  head->next = nullptr;

  ListNode *rest = reverseLLRecur(nextItem);
  nextItem->next = head;
  return rest;
}

void insertSorted(ListNode **head, int data)
{
  ListNode *newNode = new ListNode(data);
  ;

  if (!(*head) || (*head)->val >= newNode->val)
  {
    newNode->next = *head;
    *head = newNode;
    return;
  }
  ListNode *curr = *head;

  while (curr->next && curr->next->val < newNode->val)
    curr = curr->next;
  newNode->next = curr->next;
  curr->next = newNode;
}

int main()
{
  std::cout << "Radhey Shyam" << std::endl;

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  std::cout << head;
  insetIntoBeginning(&head, 1);
  std::cout << head;

  insertAtEnd(&head, 10);
  std::cout << head;

  insetAtPos(&head, 9, 77);
  std::cout << head;

  insertAfterNode(&head, head->next->next->next->next->next->next->next, 11);
  std::cout << head;

  insertSorted(&head, 100);
  std::cout << head;

  std::cout << "reverse" << std::endl;
  reverseLLIter(&head);
  std::cout << head;

  head = reverseLLRecur(head);
  std::cout << head;

  // Delete Nodes
  ListNode *curr = head;
  ListNode *next;

  while (curr)
  {
    next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
}
