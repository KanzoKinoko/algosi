
#include "one_phase_merge_sort.h"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

namespace
{
    void mergeRuns(
        std::ifstream& left,
        std::ifstream& right,
        std::ofstream& output,
        int leftSize,
        int rightSize)
    {
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
}

std::vector<int> onePhaseMergeSort(std::vector<int> arr, int size)
{
    size = std::min(size, static_cast<int>(arr.size()));

    if (size <= 1)
        return arr;

    {
        std::ofstream file("one_input.txt");

        for (int i = 0; i < size; ++i)
            file << arr[i] << ' ';
    }

    std::string source = "one_input.txt";
    std::string outputFile = "one_output_a.txt";

    for (int width = 1; width < size; width *= 2)
    {
        std::string leftFile = "one_left.txt";
        std::string rightFile = "one_right.txt";

        {
            std::ifstream input(source);
            std::ofstream left(leftFile);
            std::ofstream right(rightFile);

            int value;

            for (int i = 0; i < size; ++i)
            {
                input >> value;

                int run = i / width;

                if (run % 2 == 0)
                    left << value << ' ';
                else
                    right << value << ' ';
            }
        }

        {
            std::ifstream left(leftFile);
            std::ifstream right(rightFile);
            std::ofstream output(outputFile);

            for (int start = 0; start < size; start += 2 * width)
            {
                int leftSize = std::min(width, size - start);
                int rightSize =
                    std::min(width, size - start - leftSize);

                mergeRuns(
                    left, right, output, leftSize, rightSize);
            }
        }

        std::remove(leftFile.c_str());
        std::remove(rightFile.c_str());

        if (source != "one_input.txt")
            std::remove(source.c_str());

        source = outputFile;
        outputFile = (outputFile == "one_output_a.txt")
            ? "one_output_b.txt"
            : "one_output_a.txt";
    }

    {
        std::ifstream result(source);

        for (int i = 0; i < size; ++i)
            result >> arr[i];
    }

    std::remove("one_input.txt");
    std::remove("one_output_a.txt");
    std::remove("one_output_b.txt");

    return arr;
}