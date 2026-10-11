#include "quick_sort.h"

void quickSortPart(std::vector<int>& arr, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSortPart(arr, left, j);
    if (i < right) quickSortPart(arr, i, right);
}

std::vector<int> quickSort(std::vector<int> arr, int size)
{
    if (size > 1)
        quickSortPart(arr, 0, size - 1);

    return arr;
}
