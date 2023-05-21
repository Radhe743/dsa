#include <iostream>

struct ListNode
{
  int data;
  ListNode *next;
  ListNode(int data) : data(data) {}
};

std::ostream &operator<<(std::ostream &out, ListNode *node)
{
  if (!node)
  {
    out << "[]\n";
    return out;
  }

  out << "[ ";

  ListNode *temp = node;
  while (temp)
  {
    out << temp->data << ((temp->next) ? "," : " ]\n");
    temp = temp->next;
  }
  return out;
}
ListNode *reverseInPairs(ListNode *head)
{
  if (!head || !head->next)
    return nullptr;

  ListNode *temp = head->next;
  head->next = temp->next;
  temp->next = head;

  head = temp;

  head->next->next = reverseInPairs(head->next->next);
  return head;
}
/**

 * 1->2->3->4


  while popping from rec stack
  4->3->2->1



*/
void printListInReverse(ListNode *head)
{
  if (!head)
    return;

  printListInReverse(head->next);
  std::cout << head->data << " ";
  return;
}

/*

head  ==   1 -> 2 -> 3 -> 4 -> x;
nextElem = 2 -> 3 -> 4 -> x;
head -> nxt == null
head =  1 -> x


after rec

4 -> 3 -> 2 -> 1;

*/

ListNode *reverseListRecursive(ListNode *head)
{
  if (!head || !head->next)
    return head;

  ListNode *nextElem = head->next;

  head->next = NULL;

  ListNode *rest = reverseListRecursive(nextElem);
  nextElem->next = head;

  return rest;
}

ListNode *makeList(int *nodes, int size)
{
  ListNode *newNode = new ListNode(0);

  ListNode *temp = newNode;

  for (int i = 0; i < size; i++)
  {
    temp->next = new ListNode(nodes[i]);
    temp = temp->next;
  }

  return newNode->next;
}

ListNode *mergeSortedLists(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;

  if (!l2)
    return l1;

  if (l1->data <= l2->data)
  {
    l1->next = mergeSortedLists(l1->next, l2);
    return l1;
  }
  else
  {

    l2->next = mergeSortedLists(l1, l2->next);
    return l2;
  }
}

ListNode *mergeSortedListsIter(ListNode *l1, ListNode *l2)
{

  ListNode *dummy = new ListNode(0);
  ListNode *temp = dummy;

  while (l1 && l2)
  {
    if (l1->data <= l2->data)
    {
      temp->next = l1;
      l1 = l1->next;
    }
    else
    {
      temp->next = l2;
      l2 = l2->next;
    }
    temp = temp->next;
  }

  temp->next = l1 ? l1 : l2;

  return dummy->next;
}

// {a1,a1.a1...an} + {b2,b2.b2...am} -> {a1, b1, a2, b2, a3, b3 ...}

ListNode *alternateMerge(ListNode *l1, ListNode *l2)
{

  ListNode *newNode = new ListNode(0);
  ListNode *temp = newNode;

  while (l1 && l2)
  {
    temp->next = l1;
    l1 = l1->next;
    temp = temp->next;

    temp->next = l2;
    l2 = l2->next;
    temp = temp->next;
  }

  temp->next = l1 ? l1 : l2;

  return newNode->next;
}

ListNode *findMidElement(ListNode *head)
{
  if (!head)
    return nullptr;

  ListNode *slow, *fast;
  slow = fast = head;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

void deleteList(ListNode **head);
int main(int argc, const char **argv)
{

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  std::cout << head << std::endl;

  // head = reverseInPairs(head);
  head = reverseListRecursive(head);
  std::cout << head << std::endl;
  // printListInReverse(head);

  int l1nodes[] = {1, 2, 3, 4, 5, 6, 7};
  int l2nodes[] = {11, 12, 13, 14, 15};

  ListNode *l1 = makeList(l1nodes, sizeof(l1nodes) / sizeof(l1nodes[0]));
  ListNode *l2 = makeList(l2nodes, sizeof(l2nodes) / sizeof(l2nodes[0]));

  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;

  // ListNode *merged = mergeSortedLists(l1, l2);
  ListNode *merged = mergeSortedListsIter(l1, l2);
  std::cout << merged << std::endl;

  ListNode *mergedListMidNode = findMidElement(merged);
  std::cout << "The Middle of the merged List is: " << mergedListMidNode->data << std::endl
            << std::endl;
  // Delete

  ListNode *l3 = makeList(l1nodes, sizeof(l1nodes) / sizeof(l1nodes[0]));
  ListNode *l4 = makeList(l2nodes, sizeof(l2nodes) / sizeof(l2nodes[0]));

  std::cout << l3;
  std::cout << l4 << std::endl;

  ListNode *alternateMergedList = alternateMerge(l3, l4);
  std::cout << alternateMergedList << std::endl;

  deleteList(&merged);
  deleteList(&head);

  deleteList(&l2);
  deleteList(&l1);

  deleteList(&alternateMergedList);
  deleteList(&l3);
  deleteList(&l4);
}

void deleteList(ListNode **head)
{

  if (!(*head))
    return;

  ListNode *curr = *head;
  ListNode *next;

  while (curr)
  {
    next = curr->next;
    delete curr;
    curr = next;
  }
  delete curr;

  *head = nullptr;
}