#include <iostream>

#include "../header/SingleLinkList.hpp"

// use same unshift as b1
void addSLL(SingleLinkList<int> &sll, int val)
{
    sll.unshift(val);
}

// use same shift as b1
void undoSLL(SingleLinkList<int> &sll)
{
    // if sll is empty cannot undo
    if (sll.size() < 0)
        return;

    sll.shift();
}

void addArray(int val, int arr[], int &size, int &capacity)
{
    if (size == capacity)
        return;

    arr[size] = val;
    size++;
}

void undoArray(int arr[], int &size, int &capacity)
{
    if (size == 0)
        return;

    arr[size - 1] = 0;
    size--;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main(void)
{
    int capacity = 100;
    int size = 0;
    int arr[capacity];

    addArray(1, arr, size, capacity);
    addArray(2, arr, size, capacity);
    addArray(3, arr, size, capacity);
    display(arr, size);
    undoArray(arr, size, capacity);
    display(arr, size);
    addArray(4, arr, size, capacity);
    addArray(5, arr, size, capacity);
    addArray(6, arr, size, capacity);
    display(arr, size);
    undoArray(arr, size, capacity);
    display(arr, size);

    return 0;
}