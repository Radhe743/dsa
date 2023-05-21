def bubbleSort(arr):
    for i in range(len(arr) - 1):
        swapped = False
        for j in range(len(arr) - i - 1):
            if arr[j] >= arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped:
            break


def selectionSort(arr):
    for i in range(len(arr) - 1):
        minIdx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[minIdx]:
                minIdx = j
        arr[i], arr[minIdx] = arr[minIdx], arr[i]

# [4,5,6,7,3,2,1]


def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = key


def merge(arr, start, mid, end):
    leftArr = arr[start: mid+1]
    rightArr = arr[mid + 1: end+1]

    i = 0
    j = 0
    k = start

    while i < len(leftArr) and j < len(rightArr):
        if(leftArr[i] <= rightArr[j]):
            arr[k] = leftArr[i]
            i += 1
        else:
            arr[k] = rightArr[j]
            j += 1
        k += 1

    while i < len(leftArr):
        arr[k] = leftArr[i]
        k += 1
        i += 1

    while j < len(rightArr):
        arr[k] = rightArr[j]
        k += 1
        j += 1


def mergeSort(arr, start, end):
    if(start < end):

        mid = start + (end - start) // 2
        mergeSort(arr, start, mid)
        mergeSort(arr, mid + 1, end)
        merge(arr, start, mid, end)


def partition(arr, left, right):
    pivot = arr[left]
    i = left + 1
    j = right

    while i <= j:
        while i <= j and arr[i] < pivot:
            i += 1
        while i <= j and arr[j] > pivot:
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]

    arr[left], arr[j] = arr[j], arr[left]
    return j


def quickSort(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)
        quickSort(arr, start, pivot)
        quickSort(arr, pivot+1, end)


print("Radhey Shyam")

arr = [x for x in range(1, 8)][::-1]
print(arr)
# bubbleSort(arr)
# selectionSort(arr)
# insertionSort(arr)
# mergeSort(arr, 0, len(arr) - 1)
quickSort(arr, 0, len(arr) - 1)

print(arr)
