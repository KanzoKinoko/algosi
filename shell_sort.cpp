#include "shell_sort.h"

std::vector<int> shellSort(std::vector<int> arr, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }

    return arr;
}
