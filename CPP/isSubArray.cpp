#include <iostream>
#include <vector>
#include <string>

bool isSubArray(std::vector<int> &numbers, std::vector<int> &sub)
{
  if (sub.empty())
    return false;

  int idx = 0;
  for (auto const &number : numbers)
  {
    if (number == sub[idx])
    {
      idx++;
      if (idx == sub.size())
        break;
    }
  }
  return idx == sub.size();
}
int main(int argc, char const *argv[])
{
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> sub = {1, 4, 10};
  std::string text = (isSubArray(numbers, sub) ? "Is a SubArray" : "Not Sub Array");
  std::cout << text << std::endl;

  return 0;
}
