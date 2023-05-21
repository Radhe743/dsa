

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


def quick_sort(arr, start, end):
    if start < end:
        pivot = partition(arr, start, end)
        quick_sort(arr, start, pivot)
        quick_sort(arr, pivot+1, end)


arr = [7, 6, 5, 4, 3, 2, 1]
print(arr)
quick_sort(arr, 0, len(arr) - 1)
print(arr)
