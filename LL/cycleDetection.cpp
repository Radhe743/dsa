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

void loopPrint(ListNode *head)
{

  ListNode *temp = head;

  std::cout << "[";
  do
  {
    std::cout << temp->val << ((temp->next != head) ? ", " : "]\n");
    temp = temp->next;

  } while (temp != head);
}

bool hasLoop(ListNode *head)
{
  if (!head)
    return false;

  ListNode *slow;
  ListNode *fast;
  slow = fast = head;

  while (slow && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
      return true;
  }
  return false;
}

ListNode *findLoopBeginning(ListNode *head)
{
  if (!head)
    return nullptr;

  ListNode *slow;
  ListNode *fast;
  slow = fast = head;
  bool loopExists = false;

  while (slow && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      loopExists = true;
      break;
    }
  }

  if (loopExists)
  {
    slow = head;
    while (slow != fast)
    {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
  return nullptr;
}

int loopLength(ListNode *head)
{
  ListNode *slow, *fast;
  slow = fast = head;
  bool hasLoop = false;
  int counter = 0;

  while (slow && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      hasLoop = true;
      break;
    }
  }

  if (hasLoop)
  {
    counter = 1;
    fast = fast->next;

    while (fast != slow)
    {
      fast = fast->next;
      counter++;
    }
  }

  return counter;
}

int main(int argc, const char **argv)
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = head->next->next->next;

  // std::cout << head << std::endl;
  // loopPrint(head);

  std::string loop = (hasLoop(head)) ? "The list has loop" : "The List has no Loop";
  std::cout << loop << std::endl;

  ListNode *loopStart = findLoopBeginning(head);
  loopPrint(loopStart);

  if (loopStart)
    std::cout << "Loop begins at node:  " << loopStart->val << std::endl;

  int lengthOfLoop = loopLength(head);
  std::cout << "The length of the loop is: " << lengthOfLoop << std::endl;

  // Delete Nodes
  // ListNode *curr = head;
  // ListNode *next;

  // while (curr)
  // {
  //   next = curr->next;
  //   delete curr;
  //   curr = next;
  // }
  // head = nullptr;
}