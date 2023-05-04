#include <iostream>

struct ListNode
{
  int val;
  ListNode *next = nullptr;

  ListNode(int val) : val(val) {}
};

void reverseLL(ListNode **head)
{
  ListNode *curr = *head, *prev = nullptr, *next = nullptr;
  while (curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;

    curr = next;
  }
  *head = prev;
}

void printLL(ListNode *head);
void deleteLL(ListNode **head);

int main()
{
  std::cout << "Radhey Shyam" << std::endl;
  ListNode *l1 = new ListNode(4);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(1);

  printLL(l1);
  reverseLL(&l1);
  printLL(l1);
  deleteLL(&l1);
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