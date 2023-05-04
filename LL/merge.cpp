#include <iostream>

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void merge(int *arr, int start, int mid, int end)
{
  int mergedArrSize = end - start + 1;
  int *mergedArr = new int[mergedArrSize];
  int i = start;
  int j = mid + 1;
  int k = 0;

  while (i <= mid && j <= end)
  {
    if (arr[i] <= arr[j])
    {
      mergedArr[k++] = arr[i++];
    }
    else
    {
      mergedArr[k++] = arr[j++];
    }
  }

  while (i <= mid)
  {
    mergedArr[k++] = arr[i++];
  }
  while (j <= end)
  {
    mergedArr[k++] = arr[j++];
  }

  for (int iter = 0; iter < mergedArrSize; iter++)
  {
    arr[start + iter] = mergedArr[iter];
  }
  delete[] mergedArr;
}

void mergeSort(int *arr, int start, int end)
{
  if (start < end)
  {
    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {7, 6, 5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  mergeSort(arr, 0, size - 1);

  printArray(arr, size);

  return 0;
}
