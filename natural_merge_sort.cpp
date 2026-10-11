#include "natural_merge_sort.h"

std::vector<int> naturalMergeSort(std::vector<int> arr, int size)
{
    while (true)
    {
        std::vector<int> result;
        int i = 0;
        int runs = 0;

        while (i < size)
        {
            int mid = i + 1;
            while (mid < size && arr[mid - 1] <= arr[mid])
                mid++;

            if (mid == size)
            {
                for (int k = i; k < size; k++)
                    result.push_back(arr[k]);
                runs++;
                break;
            }

            int end = mid + 1;
            while (end < size && arr[end - 1] <= arr[end])
                end++;

            int a = i, b = mid;
            while (a < mid && b < end)
            {
                if (arr[a] <= arr[b]) result.push_back(arr[a++]);
                else result.push_back(arr[b++]);
            }

            while (a < mid) result.push_back(arr[a++]);
            while (b < end) result.push_back(arr[b++]);

            runs++;
            i = end;
        }

        arr = result;
        if (runs <= 1) break;
    }

    return arr;
}
