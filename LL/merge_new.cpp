#include <iostream>

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void merge(int *arr, int start, int mid, int end)
{
  int leftArrIdx = start, rightArrIdx = mid + 1, k = 0;
  int mergedArrSize = end - start + 1;
  int *mergedArr = new int[mergedArrSize];

  while (leftArrIdx <= mid && rightArrIdx <= end)
  {
    if (arr[leftArrIdx] <= arr[rightArrIdx])
    {
      mergedArr[k++] = arr[leftArrIdx++];
    }
    else
    {
      mergedArr[k++] = arr[rightArrIdx++];
    }
  }

  while (leftArrIdx <= mid)
  {
    mergedArr[k++] = arr[leftArrIdx++];
  }
  while (rightArrIdx <= end)
  {
    mergedArr[k++] = arr[rightArrIdx++];
  }

  for (int i = 0; i < mergedArrSize; i++)
  {
    arr[i + start] = mergedArr[i];
  }
}
void mergeSort(int *arr, int start, int end)
{
  if (end > start)
  {
    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}
int main(int argc, char const *argv[])
{
  int arr[] = {7, 6, 6, 77, 777, 5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  mergeSort(arr, 0, size - 1);

  printArray(arr, size);

  return 0;
}
