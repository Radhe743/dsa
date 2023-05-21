#include <iostream>
#include <vector>
class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int data) : val(data), next(nullptr) {}
};
std::ostream &operator<<(std::ostream &out, ListNode *node)
{
  if (!node)
  {
    out << "[]\n";
    return out;
  }

  ListNode *curr = node;
  out << "[ ";

  for (; curr; curr = curr->next)
    out << curr->val << ((curr->next) ? ", " : " ]\n");

  return out;
}

ListNode *createList(std::vector<int> nodes)
{
  ListNode *newNode = new ListNode(0);
  ListNode *temp = newNode;

  for (int const &nodeVal : nodes)
  {
    temp->next = new ListNode(nodeVal);
    temp = temp->next;
  }

  return newNode->next;
}

int listLength(ListNode *head)
{
  if (!head)
    return 0;
  int length = 0;

  ListNode *curr = head;
  for (; curr; curr = curr->next)
    length++;

  return length;
}

// [ 1, 2, 3, 4, 5, 6, 7 ]
//  2

// [ 6, 7, 1, 2, 3, 4, 5 ]
//
ListNode *shiftList(ListNode *head, int k)
{
  if (!head)
    return head;

  // O(n)
  int length = listLength(head);

  k = k % length;

  // Adjust for negative values
  if (k < 0)
    k += length;

  if (k == 0)
    return head;

  ListNode *curr = head;

  for (int i = 0; i < length - k - 1; i++)
  {
    curr = curr->next;
  }
  ListNode *newTail = curr;
  ListNode *newHead = curr->next;

  curr = newHead;
  for (; curr->next; curr = curr->next)
    ;
  curr->next = head;
  newTail->next = nullptr;
  return newHead;
}
ListNode *mergeLists(ListNode *l1, ListNode *l2)

{
  ListNode *dummy = new ListNode(0);
  ListNode *curr = dummy;

  while (l1 && l2)
  {
    if (l1->val <= l2->val)
    {
      curr->next = l1;
      l1 = l1->next;
    }
    else
    {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }

  if (l1)
    curr->next = l1;

  if (l2)
    curr->next = l2;

  return dummy->next;
}
ListNode *swapPairs(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *newHead = head->next;
  head->next = swapPairs(newHead->next);
  newHead->next = head;
  return newHead;
}
ListNode *swapPairsIter(ListNode *head)
{
  if (!head || !head->next)
    return head;

  // dummy(0) [ 1, 2, 3, 4, 5, 6, 7 ]

  // dummy(0) [ 2, 1, 3, 4, 5, 6, 7 ]

  // dummy(0) [ 2, 1, 3, 4, 5, 6, 7 ]

  // dummy(0) [ 2, 1, 4, 3, 5, 6, 7 ]

  // dummy(0) [ 2, 1, 4, 3, 6, 5, 7 ]

  ListNode *dummy = new ListNode(0);
  dummy->next = head;

  ListNode *curr = head;
  ListNode *prev = dummy;

  while (curr && curr->next)
  {
    ListNode *next = curr->next;
    ListNode *nextNext = next->next;

    prev->next = next;
    next->next = curr;
    curr->next = nextNext;
    prev = curr;
    curr = nextNext;
  }
  head = dummy->next;
  delete dummy;
  return head;
}

int main(int argc, char const *argv[])
{
  std::cout << "Radhey Shyam"
            << "\n";

  ListNode *head = createList({1, 2, 3, 4, 5, 6, 7});
  ListNode *list = createList({
      7,
      10,
      10,
      20,
      89,
  });
  std::cout << head;
  // head = swapPairs(head);
  head = swapPairsIter(head);
  // head = shiftList(head, -1);
  std::cout << head;

  ListNode *merged = mergeLists(head, list);

  std::cout << merged;
  return 0;
}
