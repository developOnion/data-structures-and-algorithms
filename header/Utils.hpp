#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

namespace SortingIntArr
{
    void bubbleSort(int arr[], int length);
    void selectionSort(int arr[], int length);
    void insertionSort(int arr[], int length);
    void quickSort(int arr[], int length);
    void mergeSort(int arr[], int length);
}

namespace Printing
{
    void printArr(int arr[], int length);
}

#endif