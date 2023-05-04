#include <iostream>

void merge(int *arr, int start, int mid, int end)
{
  int leftSize = mid - start + 1;
  int rightSize = end - mid;

  int *leftArr = new int[leftSize];
  int *rightArr = new int[rightSize];

  for (int i = 0; i < leftSize; i++)
    leftArr[i] = arr[start + i];

  for (int j = 0; j < rightSize; j++)
    rightArr[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = start;

  while (i < leftSize && j < rightSize)
  {
    if (leftArr[i] <= rightArr[j])
      arr[k++] = leftArr[i++];

    else
      arr[k++] = rightArr[j++];
  }

  while (i < leftSize)
    arr[k++] = leftArr[i++];

  while (j < rightSize)
    arr[k++] = rightArr[j++];

  delete[] leftArr;
  delete[] rightArr;
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

void printArray(int *arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

int main(int argc, char const *argv[])
{
  int arr[] = {6, 10, 7, 5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  mergeSort(arr, 0, size - 1);

  printArray(arr, size);

  return 0;
}
