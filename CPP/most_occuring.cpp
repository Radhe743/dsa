#include <iostream>
#include <algorithm>
void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}
int getMostOccurringDigit(int *arr, int size)
{
  int count[10] = {0};

  for (int i = 0; i < size; i++)
  {
    int num = arr[i];

    while (num != 0)
    {
      int digit = num % 10;
      count[digit]++;
      num /= 10;
    }
  }

  int mostOccurringDigit = 0;
  int maxCount = count[0];

  for (int i = 1; i < 10; i++)
  {
    if (count[i] > maxCount)
    {
      mostOccurringDigit = i;
      maxCount = count[i];
    }
  }

  return mostOccurringDigit;
}

int getMostOccurringItem(int *arr, int size)
{
  int maxCount = 0;
  int currCount = 0;
  int mostOccurredItem = arr[0];

  std::sort(arr, arr + size);

  for (int i = 1; i < size; i++)
  {
    if (arr[i] == arr[i - 1])
    {
      if (currCount > maxCount)
      {
        maxCount = currCount;
        mostOccurredItem = arr[i];
      }
    }
    else
    {
      currCount = 0;
    }
  }
  return mostOccurredItem;
}

int main(int argc, char const *argv[])
{
  int arr[] = {7, 6, 6, 77, 77, 99999, 5, 7, 4, 3, 7, 7, 2, 7, 1};

  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  int mostOccurringDigit = getMostOccurringDigit(arr, size);
  std::cout << "The Most Occurring Digit in the array is: " << mostOccurringDigit << std::endl;

  int mostOccurringItem = getMostOccurringItem(arr, size);
  std::cout << "The Most Occurring Item in the array is: " << mostOccurringItem << std::endl;

  return 0;
}
