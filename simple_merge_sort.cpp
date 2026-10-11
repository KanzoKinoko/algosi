#include "simple_merge_sort.h"

void mergeSortPart(std::vector<int>& arr, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSortPart(arr, left, mid);
    mergeSortPart(arr, mid + 1, right);

    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

std::vector<int> simpleMergeSort(std::vector<int> arr, int size)
{
    mergeSortPart(arr, 0, size - 1);
    return arr;
}
