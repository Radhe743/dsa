#include <stack>
#include <iostream>
#include <string>

bool isPalindromeX(std::string str)
{
  int idx = 0;
  std::stack<char> s;

  while (str[idx] != 'X')
  {
    s.push(str[idx]);
    idx++;
  }

  idx++;

  while (!s.empty() && idx < str.size())
  {
    if (s.top() != str[idx])
      return false;

    s.pop();
    idx++;
  }
  return true;
}

int main()
{
  std::string str = "racecarXracecar";
  bool isPal = isPalindromeX(str);

  (isPal) ? std::cout << "Is Palindrome" : std::cout << "Not Palindrome!!";
}
