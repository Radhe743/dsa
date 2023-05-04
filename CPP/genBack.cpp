#include <iostream>
#include <stack>
#include <vector>
#include <string>

void backtrack(std::string curr, int open, int close, int n, std::vector<std::string> &result)
{
  if (curr.length() == n * 2)
  {
    result.push_back(curr);
    return;
  }

  if (open < n)
    backtrack(curr + "(", open + 1, close, n, result);

  if (close < open)
    backtrack(curr + ")", open, close + 1, n, result);
}

std::vector<std::string> genBrackets(int n)
{
  std::vector<std::string> result;

  backtrack("", 0, 0, n, result);

  return result;
}

std::vector<std::string> genBracketsIter(int n)
{
  std::stack<std::pair<std::string, int>> s;
  std::vector<std::string> result;

  s.push(std::make_pair("", 0));

  while (!s.empty())
  {
    std::string curr = s.top().first;
    int openCount = s.top().second;
    s.pop();

    if (curr.length() == n * 2)
      result.push_back(curr);
    else
    {
      if (openCount < n)
        s.push(std::make_pair(curr + "(", openCount + 1));

      if (curr.length() < openCount * 2)
        s.push(std::make_pair(curr + ")", openCount));
    }
  }
  return result;
}

int main(int argc, char const *argv[])
{

  std::vector<std::string> result = genBrackets(3);
  for (auto item : result)
  {
    std::cout << item << "\n";
  }
  return 0;
}
