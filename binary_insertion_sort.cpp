#include "binary_insertion_sort.h"

std::vector<int> binaryInsertionSort(std::vector<int> arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int left = 0;
        int right = i;

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] <= key)
                left = mid + 1;
            else
                right = mid;
        }

        for (int j = i; j > left; j--)
            arr[j] = arr[j - 1];

        arr[left] = key;
    }
    return arr;
}
