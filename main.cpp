
#include <catch2/catch_test_macros.hpp>
#include <vector>

#include "insertion_sort.h"
#include "selection_sort.h"
#include "exchange_sort.h"
#include "bubble_sort.h"
#include "optimized_bubble_sort.h"
#include "binary_insertion_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "simple_merge_sort.h"
#include "one_phase_merge_sort.h"
#include "natural_merge_sort.h"

using SortFunction = std::vector<int>(*)(std::vector<int>, int);

void testSort(SortFunction sort)
{
    SECTION("already_sorted")
    {
        std::vector<int> arr = {1, 2, 3, 4, 5};
        std::vector<int> ans = {1, 2, 3, 4, 5};

        REQUIRE(sort(arr, static_cast<int>(arr.size())) == ans);
    }

    SECTION("reverse_sorted")
    {
        std::vector<int> arr = {5, 4, 3, 2, 1};
        std::vector<int> ans = {1, 2, 3, 4, 5};

        REQUIRE(sort(arr, static_cast<int>(arr.size())) == ans);
    }

    SECTION("random_order")
    {
        std::vector<int> arr = {4,0,15,6,12,2,14,8};
        std::vector<int> ans = {0, 2, 4, 6, 8, 12, 14, 15};

        REQUIRE(sort(arr, static_cast<int>(arr.size())) == ans);
    }

    SECTION("duplicate_elements")
    {
        std::vector<int> arr = {4, 2, 4, 1, 2};
        std::vector<int> ans = {1, 2, 2, 4, 4};

        REQUIRE(sort(arr, static_cast<int>(arr.size())) == ans);
    }
}

TEST_CASE("insertion_sort")
{
    testSort(insertionSort);
}

TEST_CASE("selection_sort")
{
    testSort(selectionSort);
}

TEST_CASE("exchange_sort")
{
    testSort(exchangeSort);
}

TEST_CASE("bubble_sort")
{
    testSort(bubbleSort);
}

TEST_CASE("optimized_bubble_sort")
{
    testSort(optimizedBubbleSort);
}

TEST_CASE("binary_insertion_sort")
{
    testSort(binaryInsertionSort);
}

TEST_CASE("shaker_sort")
{
    testSort(shakerSort);
}

TEST_CASE("shell_sort")
{
    testSort(shellSort);
}

TEST_CASE("quick_sort")
{
    testSort(quickSort);
}

TEST_CASE("simple_merge_sort")
{
    testSort(simpleMergeSort);
}

TEST_CASE("one_phase_merge_sort")
{
    testSort(onePhaseMergeSort);
}

TEST_CASE("natural_merge_sort")
{
    testSort(naturalMergeSort);
}

