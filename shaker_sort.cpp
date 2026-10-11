#include "shaker_sort.h"

std::vector<int> shakerSort(std::vector<int> arr, int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        for (int i = left; i < right; i++)
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        right--;

        for (int i = right; i > left; i--)
            if (arr[i - 1] > arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        left++;
    }
    return arr;
}
