#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

std::unordered_map<char, char> brackets = {
    {')', '('},
    {']', '['},
    {'}', '{'}};

bool checkParenthesis(const std::string &str)
{
  std::stack<char> s;
  for (char c : str)
  {

    if (c == '(' || c == '{' || c == '[')
    {
      s.push(c);
    }
    else if (c == ')' || c == '}' || c == ']')
    {

      if (s.empty() || brackets[c] != s.top())
        return false;

      s.pop();
    }
  }
  return s.empty();
}

int main(int argc, char const *argv[])
{
  std::string exp = "({[{}]})";

  bool isValid = checkParenthesis(exp);

  isValid ? std::cout << "Valid" : std::cout << "Invalid";

  return 0;
}
