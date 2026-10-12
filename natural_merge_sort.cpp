
#include "natural_merge_sort.h"

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
                --leftSize;
                hasA = leftSize > 0 && static_cast<bool>(left >> a);
            }
            else
            {
                output << b << ' ';
                --rightSize;
                hasB = rightSize > 0 && static_cast<bool>(right >> b);
            }
        }

        while (hasA)
        {
            output << a << ' ';
            --leftSize;
            hasA = leftSize > 0 && static_cast<bool>(left >> a);
        }

        while (hasB)
        {
            output << b << ' ';
            --rightSize;
            hasB = rightSize > 0 && static_cast<bool>(right >> b);
        }
    }
}

std::vector<int> naturalMergeSort(std::vector<int> arr, int size)
{
    size = std::min(size, static_cast<int>(arr.size()));

    if (size <= 1)
        return arr;

    {
        std::ofstream file("natural_input.txt");

        for (int i = 0; i < size; ++i)
            file << arr[i] << ' ';
    }

    std::string source = "natural_input.txt";
    std::string outputFile = "natural_output_a.txt";

    while (true)
    {
        std::vector<int> leftRuns;
        std::vector<int> rightRuns;


        {
            std::ifstream input(source);
            std::ofstream left("natural_left.txt");
            std::ofstream right("natural_right.txt");

            int previous;

            if (!(input >> previous))
                break;

            int runIndex = 0;
            int runSize = 1;

            std::ofstream* target = &left;
            target->clear();
            *target << previous << ' ';

            int current;

            while (input >> current)
            {
                if (current < previous)
                {
                    if (runIndex % 2 == 0)
                        leftRuns.push_back(runSize);
                    else
                        rightRuns.push_back(runSize);

                    ++runIndex;
                    runSize = 1;

                    target = (runIndex % 2 == 0)
                        ? &left
                        : &right;
                }
                else
                {
                    ++runSize;
                }

                *target << current << ' ';
                previous = current;
            }

            if (runIndex % 2 == 0)
                leftRuns.push_back(runSize);
            else
                rightRuns.push_back(runSize);
        }

        int runs = static_cast<int>(
            leftRuns.size() + rightRuns.size());

  
        if (runs <= 1)
            break;

  
        {
            std::ifstream left("natural_left.txt");
            std::ifstream right("natural_right.txt");
            std::ofstream output(outputFile);

            for (int i = 0;
                 i < static_cast<int>(leftRuns.size());
                 ++i)
            {
                int leftSize = leftRuns[i];

                int rightSize =
                    i < static_cast<int>(rightRuns.size())
                    ? rightRuns[i]
                    : 0;

                mergeRuns(
                    left, right, output,
                    leftSize, rightSize);
            }
        }

        std::remove("natural_left.txt");
        std::remove("natural_right.txt");

        if (source != "natural_input.txt")
            std::remove(source.c_str());

        source = outputFile;

        outputFile = (outputFile == "natural_output_a.txt")
            ? "natural_output_b.txt"
            : "natural_output_a.txt";
    }


    {
        std::ifstream result(source);

        for (int i = 0; i < size; ++i)
            result >> arr[i];
    }

    std::remove("natural_input.txt");
    std::remove("natural_left.txt");
    std::remove("natural_right.txt");
    std::remove("natural_output_a.txt");
    std::remove("natural_output_b.txt");

    return arr;
}