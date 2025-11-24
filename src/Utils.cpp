#include "../header/Utils.hpp"

namespace SortingIntArr
{
    void swap(int &a, int &b)
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

    static int partition(int arr[], int low, int high)
    {
        int pivotIndex = low + (std::rand() % (high - low));
        if (pivotIndex != high)
            swap(arr[pivotIndex], arr[high]);

        int pivotVal = arr[high];
        int i = low;
        for (int j = low; j < high; ++j)
        {
            if (arr[j] <= pivotVal)
            {
                swap(arr[j], arr[i]);
                i++;
            }
        }

        swap(arr[high], arr[i]);

        return i;
    }

    static void quickSortHelper(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = SortingIntArr::partition(arr, low, high);
            SortingIntArr::quickSortHelper(arr, low, pivotIndex - 1);
            SortingIntArr::quickSortHelper(arr, pivotIndex + 1, high);
        }
    }

    void quickSort(int arr[], int length)
    {
        std::srand(std::time(NULL));
        SortingIntArr::quickSortHelper(arr, 0, length - 1);
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