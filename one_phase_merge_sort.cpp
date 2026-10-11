#include "one_phase_merge_sort.h"

std::vector<int> onePhaseMergeSort(std::vector<int> arr, int size)
{
    for (int width = 1; width < size; width *= 2)
    {
        std::vector<int> temp;

        for (int start = 0; start < size; start += 2 * width)
        {
            int mid = start + width;
            int end = start + 2 * width;

            if (mid > size) mid = size;
            if (end > size) end = size;

            int i = start, j = mid;

            while (i < mid && j < end)
            {
                if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
                else temp.push_back(arr[j++]);
            }

            while (i < mid) temp.push_back(arr[i++]);
            while (j < end) temp.push_back(arr[j++]);
        }

        arr = temp;
    }
    return arr;
}
