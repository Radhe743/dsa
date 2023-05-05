#include <iostream>
#include <stack>
#include <vector>

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

// Intersecting node O(m + 1)

ListNode *intersectionFinderStack(ListNode *head1, ListNode *head2)
{
  std::stack<ListNode *> s1;
  std::stack<ListNode *> s2;

  while (head1)
  {
    s1.push(head1);
    head1 = head1->next;
  }

  while (head2)
  {
    s2.push(head2);
    head2 = head2->next;
  }

  ListNode *prevMatch = nullptr;

  while (!s1.empty() && !s2.empty())
  {
    ListNode *node1 = s1.top();
    ListNode *node2 = s2.top();
    if (node1 == node2)
    {
      prevMatch = node1;
      s1.pop();
      s2.pop();
    }
    else
    {
      return prevMatch;
    }
  }
  return nullptr;
}

// Intersecting node O(mn)
ListNode *intersectionFinder(ListNode *head1, ListNode *head2)
{
  ListNode *temp;

  while (head1)
  {
    temp = head2;

    while (temp)
    {
      if (temp == head1)
        return head1;

      temp = temp->next;
    }
    head1 = head1->next;
  }

  return nullptr;
}

int main()
{
  std::cout << "Radhey Shyam" << std::endl;

  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(3);
  head1->next->next = new ListNode(4);

  ListNode *head2 = new ListNode(7);
  head2->next = new ListNode(8);
  head2->next->next = new ListNode(9);

  ListNode *intersectionList = new ListNode(11);
  intersectionList->next = new ListNode(20);
  intersectionList->next->next = new ListNode(30);

  // Connect at intersection
  head1->next->next->next = intersectionList;
  head2->next->next->next = intersectionList;

  /*
    1 -> 2 -> 3 -> 4       ( Intersection )
                    \     |
                     -  [10] -> 20 ->  30
                    /
       7 -> 8 -> 9

  */
  std::cout << "Intersection: " << intersectionList;
  std::cout << "Head 1: " << head1;
  std::cout << "Head 1: " << head2;

  ListNode *intersectionNode = intersectionFinderStack(head1, head2);
  if (intersectionNode)
    std::cout << "The Both lists intersect at node "
              << "[ " << intersectionNode->val << " ]\n";
}
