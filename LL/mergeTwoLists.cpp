#include <iostream>
struct ListNode
{
  int val;
  ListNode *next = nullptr;

  ListNode(int val) : val(val) {}
};

ListNode *mergeListsRecur(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;

  if (!l2)
    return l1;

  if (l1->val <= l2->val)
  {
    l1->next = mergeListsRecur(l1->next, l2);
    return l1;
  }
  else
  {
    l2->next = mergeListsRecur(l1, l2->next);
    return l2;
  }
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

  curr->next = (l1) ? l1 : l2;

  ListNode *merged = dummy->next;
  delete dummy;
  return merged;
}

void deleteLL(ListNode **head);
void printLL(ListNode *head);

int main()
{
  std::cout << "Radhey Shyam" << std::endl;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(3);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(6);
  l2->next = new ListNode(10);
  l2->next->next = new ListNode(11);

  printLL(l1);
  printLL(l2);

  ListNode *merged = mergeListsRecur(l1, l2);
  printLL(merged);

  deleteLL(&merged);
}

void printLL(ListNode *head)
{
  if (!head)
  {
    std::cout << "[]" << std::endl;
    return;
  }

  ListNode *curr = head;

  std::cout << "[";
  while (curr)
  {
    std::cout << curr->val << (curr->next ? "," : "]\n");
    curr = curr->next;
  }
}
void deleteLL(ListNode **head)
{
  ListNode *curr = *head;
  ListNode *next;

  while (curr)
  {
    next = curr->next;
    delete curr;
    curr = next;
  }
  *head = nullptr;
}