#include <iostream>

void sort(int *arr, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    bool swapped = false;

    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }

      if (!swapped)
        break;
    }
  }
}

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

int main(int argc, char const *argv[])
{
  int arr[] = {7, 6, 6, 5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  sort(arr, size);
  printArray(arr, size);

  return 0;
}
