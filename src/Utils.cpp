#include "../header/Utils.hpp"

namespace SortingIntArr
{
    static void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void bubbleSort(int arr[], int length)
    {
        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = 0; j < length - i - 1; ++j)
            {
                if (arr[j] < arr[i])
                    swap(arr[i], arr[j]);
            }
        }
    }

    void insertionSort(int arr[], int length)
    {
        for (int i = 1; i < length; ++i)
        {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void selectionSort(int arr[], int length)
    {
        for (int i = 0; i < length; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < length; ++j)
                if (arr[j] < arr[minIndex])
                    minIndex = j;

            if (minIndex != i)
                swap(arr[i], arr[minIndex]);
        }
    }

    /*
        all value that is lower than pivot stays on the left side
        of the pivot the rest are on the right side
    */
    static int partition(int arr[], int low, int high)
    {
        // generate a num and swap with high so pivot is flexible
        int randomNum = low + (std::rand() % (high - low));
        swap(arr[randomNum], arr[high]);

        int pivotVal = arr[high];
        int left = low;
        for (int i = low; i < high; ++i)
        {
            if (arr[i] < pivotVal)
            {
                swap(arr[i], arr[left]);
                left++;
            }
        }

        swap(arr[left], arr[high]);

        return left;
    }

    // call quicksort recursively
    static void quickSortHelper(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            quickSortHelper(arr, low, pivotIndex - 1);
            quickSortHelper(arr, pivotIndex + 1, high);
        }
    }

    // quicksort wrapper
    void quickSort(int arr[], int length)
    {
        std::srand(std::time(NULL));
        quickSortHelper(arr, 0, length - 1);
    }
}

namespace Printing
{
    void printArr(int arr[], int length)
    {
        for (int i = 0; i < length; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
}