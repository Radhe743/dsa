#include <iostream>

int partition(int *arr, int left, int right)
{

  int pivot = arr[left];
  int i = left + 1;
  int j = right;

  while (i <= j)
  {
    while (i <= j && arr[i] < pivot)
      i++;
    while (i <= j && arr[j] > pivot)
      j--;

    if (i <= j)
      std::swap(arr[i], arr[j]);
  }

  std::swap(arr[left], arr[j]);
  return j;
}

void quickSort(int *arr, int start, int end)
{
  if (start < end)
  {
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot);
    quickSort(arr, pivot + 1, end);
  }
}
void selectionSort(int *arr, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int minIdx = i;

    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    std::swap(arr[minIdx], arr[i]);
  }
}

void insertionSort(int *arr, int size)
{
  for (int i = 1; i < size; i++)
  {
    int key = arr[i];
    int j = i - 1;
    for (j; j >= 0 && arr[j] > key; j--)
      arr[j + 1] = arr[j];

    arr[j + 1] = key;
  }
}
void merge(int *arr, int left, int mid, int right)
{
  int leftArrSize = mid - left + 1;
  int rightArrSize = right - mid;

  int *leftArr = new int[leftArrSize];
  int *rightArr = new int[rightArrSize];

  for (int i = 0; i < leftArrSize; i++)
    leftArr[i] = arr[i + left];

  for (int j = 0; j < rightArrSize; j++)
    rightArr[j] = arr[j + mid + 1];

  int i = 0;
  int j = 0;
  int k = left;

  for (; i < leftArrSize && j < rightArrSize; k++)
  {
    if (leftArr[i] < rightArr[j])
      arr[k] = leftArr[i++];
    else
      arr[k] = rightArr[j++];
  }

  for (; i < leftArrSize; i++, k++)
    arr[k] = leftArr[i];

  for (; j < rightArrSize; j++, k++)
    arr[k] = rightArr[j];

  delete[] leftArr;
  delete[] rightArr;
}

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

void print(int *arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc, char const *argv[])
{
  int arr[] = {7, 6, 5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  std::cout << "Radhey Shyam "
            << "\n\n";

  print(arr, size);
  // quickSort(arr, 0, size - 1);
  // selectionSort(arr, size);
  // insertionSort(arr, size);
  // mergeSort(arr, 0, size - 1);
  bubbleSort(arr, size);
  print(arr, size);
  return 0;
}
