
#include "simple_merge_sort.h"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

namespace
{
    void mergeFiles(
        const std::string& leftFile,
        const std::string& rightFile,
        const std::string& outputFile,
        int leftSize,
        
        int rightSize)
    {
        std::ifstream left(leftFile);
        std::ifstream right(rightFile);
        std::ofstream output(outputFile);

        int a = 0, b = 0;
        bool hasA = leftSize > 0 && static_cast<bool>(left >> a);
        bool hasB = rightSize > 0 && static_cast<bool>(right >> b);

        while (hasA && hasB)
        {
            if (a <= b)
            {
                output << a << ' ';
                hasA = --leftSize > 0 && static_cast<bool>(left >> a);
            }
            else
            {
                output << b << ' ';
                hasB = --rightSize > 0 && static_cast<bool>(right >> b);
            }
        }

        while (hasA)
        {
            output << a << ' ';
            hasA = --leftSize > 0 && static_cast<bool>(left >> a);
        }

        while (hasB)
        {
            output << b << ' ';
            hasB = --rightSize > 0 && static_cast<bool>(right >> b);
        }
    }

    void externalMergeSort(
        const std::string& inputFile,
        const std::string& outputFile,
        int size,
        const std::string& prefix)
    {
        if (size <= 1)
        {
            std::ifstream input(inputFile);
            std::ofstream output(outputFile);
            int value;

            while (input >> value)
                output << value << ' ';

            return;
        }

        int leftSize = size / 2;
        int rightSize = size - leftSize;

        std::string leftFile = prefix + "_left.txt";
        std::string rightFile = prefix + "_right.txt";
        std::string sortedLeft = prefix + "_sorted_left.txt";
        std::string sortedRight = prefix + "_sorted_right.txt";

        {
            std::ifstream input(inputFile);
            std::ofstream left(leftFile);
            std::ofstream right(rightFile);

            int value;

            for (int i = 0; i < leftSize; ++i)
            {
                input >> value;
                left << value << ' ';
            }

            for (int i = 0; i < rightSize; ++i)
            {
                input >> value;
                right << value << ' ';
            }
        }

        externalMergeSort(
            leftFile, sortedLeft, leftSize, prefix + "L");

        externalMergeSort(
            rightFile, sortedRight, rightSize, prefix + "R");

        mergeFiles(
            sortedLeft, sortedRight, outputFile,
            leftSize, rightSize);

        std::remove(leftFile.c_str());
        std::remove(rightFile.c_str());
        std::remove(sortedLeft.c_str());
        std::remove(sortedRight.c_str());
    }
}

std::vector<int> simpleMergeSort(std::vector<int> arr, int size)
{
    size = std::min(size, static_cast<int>(arr.size()));

    if (size <= 1)
        return arr;

    {
        std::ofstream input("simple_input.txt");

        for (int i = 0; i < size; ++i)
            input << arr[i] << ' ';
    }

    externalMergeSort(
        "simple_input.txt",
        "simple_output.txt",
        size,
        "simple_temp");

    {
        std::ifstream output("simple_output.txt");

        for (int i = 0; i < size; ++i)
            output >> arr[i];
    }

    std::remove("simple_input.txt");
    std::remove("simple_output.txt");

    return arr;
}