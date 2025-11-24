#include <iostream>

#include "./src/Utils.hpp"

int main(void)
{
    int nums[] = {7, 8, 2, 4, 1, 0};
    int length = sizeof(nums) / sizeof(nums[0]);
    std::cout << "initial arr: ";
    Printing::printArr(nums, length);
    std::cout << "length: " << length << "\n";

    // SortingIntArr::bubbleSort(nums, length);
    // SortingIntArr::selectionSort(nums, length);
    // SortingIntArr::insertionSort(nums, length);
    SortingIntArr::quickSort(nums, length);
    std::cout << "sorted arr: ";
    Printing::printArr(nums, length);

    return 0;
}