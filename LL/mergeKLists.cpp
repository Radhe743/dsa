#include <iostream>
#include <vector>

struct ListNode
{
  int val;
  ListNode *next = nullptr;

  ListNode(int val) : val(val) {}
};

void printLL(ListNode *head);
void deleteLL(ListNode **head);

ListNode *merge(ListNode *l1, ListNode *l2)
{
  if (!l1)
    return l2;
  if (!l2)
    return l1;

  if (l1->val <= l2->val)
  {
    l1->next = merge(l1->next, l2);
    return l1;
  }
  else
  {
    l2->next = merge(l2->next, l2);
    return l2;
  }
}
ListNode *mergeHelper(std::vector<ListNode *> &lists, int start, int end)
{
  if (start == end)
    return lists[start];

  int mid = start + (end - start) / 2;
  ListNode *left = mergeHelper(lists, start, mid);
  ListNode *right = mergeHelper(lists, mid + 1, end);
  return merge(left, right);
}
ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
  int length = lists.size();
  if (lists.size() == 0)
    return nullptr;

  return mergeHelper(lists, 0, length - 1);
}

int main()
{
  std::cout << "Radhey Shyam" << std::endl;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(3);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(6);
  l2->next = new ListNode(10);
  l2->next->next = new ListNode(11);

  ListNode *l3 = new ListNode(20);
  l3->next = new ListNode(30);
  l3->next->next = new ListNode(40);

  printLL(l1);
  printLL(l2);
  printLL(l3);

  std::vector<ListNode *> lists = {l1, l2, l3};
  ListNode *merged = mergeKLists(lists);
  printLL(merged);
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