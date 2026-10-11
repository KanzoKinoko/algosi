#include "optimized_bubble_sort.h"

std::vector<int> optimizedBubbleSort(std::vector<int> arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool changed = false;

        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                changed = true;
            }

        if (!changed)
            break;
    }
    return arr;
}
