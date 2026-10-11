#include "selection_sort.h"

std::vector<int> selectionSort(std::vector<int> arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}
