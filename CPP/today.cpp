#include <iostream>
#include "utils.h"

void bubbleSort(int *arr, int size)
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
    }

    if (!swapped)
      break;
  }
}

void merge1(int *arr, int start, int mid, int end)
{
  int leftArrIdx = start;
  int rightArrIdx = mid + 1;
  int k = 0;
  int mergedArrSize = (end - start) + 1;
  int *mergedArr = new int[mergedArrSize];

  while (leftArrIdx <= mid && rightArrIdx <= end)
  {
    if (arr[leftArrIdx] <= arr[rightArrIdx])
      mergedArr[k++] = arr[leftArrIdx++];
    else
      mergedArr[k++] = arr[rightArrIdx++];
  }

  while (leftArrIdx <= mid)
    mergedArr[k++] = arr[leftArrIdx++];

  while (rightArrIdx <= mid)
    mergedArr[k++] = arr[rightArrIdx++];

  for (int i = 0; i < mergedArrSize; i++)
    arr[i + start] = mergedArr[i];
}

void merge2(int *arr, int start, int mid, int end)
{
  int leftSize = mid - start + 1;
  int rightSize = end - mid;
  int *leftArr = new int[leftSize];
  int *rightArr = new int[rightSize];

  for (int i = 0; i < leftSize; i++)
    leftArr[i] = arr[i + start];
  for (int i = 0; i < rightSize; i++)
    rightArr[i] = arr[i + mid + 1];

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
    // merge1(arr, start, mid, end);
    merge2(arr, start, mid, end);
  }
}

int findMostOccurringDigit(int *arr, int size)
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

  for (int i = 0; i < 10; i++)
  {
    if (count[i] > maxCount)
    {
      maxCount = count[i];
      mostOccurringDigit = i;
    }
  }
  return mostOccurringDigit;
}

int findMostOccurringDigitMoreSpace(int *arr, int size)
{
  int mostOccurringDigit = 0;
  int maxCount = 0;

  for (int i = 0; i < 10; i++)
  {
    int counter = 0;

    for (int j = 0; j < size; j++)
    {
      int num = arr[i];
      while (num != 0)
      {
        int digit = num % 10;
        if (i == digit)
          counter++;
        num /= 10;
      }
    }

    if (counter > maxCount)
    {
      maxCount = counter;
      mostOccurringDigit = i;
    }
  }
  return mostOccurringDigit;
}

int findMostOccurringItem(int *arr, int size)
{
  mergeSort(arr, 0, size - 1);

  int mostOccurringItem = 0;
  int maxCount = 0;
  int counter = 0;

  for (int i = 1; i < size; i++)
  {
    if (arr[i] == arr[i - 1])
    {
      counter++;
      if (counter > maxCount)
      {
        maxCount = counter;
        mostOccurringItem = arr[i];
      }
    }
    else
    {
      counter = 0;
    }
  }
  return mostOccurringItem;
}

int main()
{
  int arr[] = {7, 6, 5, 4, 3, 2, 2, 9, 9, 9, 9, 7777, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, size);
  // bubbleSort(arr, size);
  // mergeSort(arr, 0, size - 1);
  // printArray(arr, size);

  int mostOccurringItem = findMostOccurringItem(arr, size);
  int mostOccurringDigit = findMostOccurringDigitMoreSpace(arr, size);

  std::cout << "The most occurring digit in the array is : " << mostOccurringDigit << "\n";
  std::cout << "The most occurring item in the array is : " << mostOccurringItem << "\n";

  return 0;
}