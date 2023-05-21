#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;

  ListNode(int value = 0, ListNode *nxt = nullptr)
      : val(value), next(nxt) {}
};

std::ostream &operator<<(std::ostream &os, const ListNode *node)
{
  os << "[";
  while (node)
  {
    os << node->val;
    if (node->next)
    {
      os << ",";
    }
    node = node->next;
  }
  os << "]"
     << "\n";
  return os;
}

ListNode *mergeSortedLists(ListNode *list1, ListNode *list2)
{
  ListNode *dummy = new ListNode(0);
  ListNode *current = dummy;

  while (list1 && list2)
  {
    if (list1->val <= list2->val)
    {
      current->next = list1;
      list1 = list1->next;
    }
    else
    {
      current->next = list2;
      list2 = list2->next;
    }
    current = current->next;
  }
  if (list1)
    current->next = list1;
  if (list2)
    current->next = list2;

  return dummy->next;
}

ListNode *mergeListsRecursive(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;

  if (!l2)
    return l1;

  if (l1->val <= l2->val)
  {
    l1->next = mergeListsRecursive(l1->next, l2);
    return l1;
  }
  else
  {
    l2->next = mergeListsRecursive(l1, l2->next);
    return l2;
  }
}

int main(int argc, char const *argv[])
{
  ListNode *list_1 = new ListNode(1);
  ListNode *list_1_node2 = new ListNode(2);
  ListNode *list_1_node3 = new ListNode(3);
  ListNode *list_1_node4 = new ListNode(4);
  list_1->next = list_1_node2;
  list_1_node2->next = list_1_node3;
  list_1_node3->next = list_1_node4;

  ListNode *list_2 = new ListNode(4);
  ListNode *list_2_node2 = new ListNode(5);
  ListNode *list_2_node3 = new ListNode(10);
  ListNode *list_2_node4 = new ListNode(11);
  list_2->next = list_2_node2;
  list_2_node2->next = list_2_node3;
  list_2_node3->next = list_2_node4;

  std::cout << list_1;
  std::cout << list_2;
  ListNode *merged = mergeSortedLists(list_1, list_2);

  std::cout << merged << std::endl;

  delete list_2;
  delete list_2_node2;
  delete list_2_node3;
  delete list_2_node4;

  delete list_1;
  delete list_1_node2;
  delete list_1_node3;
  delete list_1_node4;
  return 0;
}
