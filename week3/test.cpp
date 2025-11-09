#include <iostream>

#include "../src/DoubleLinkList.hpp"
#include "../src/CircularLinkList.hpp"
#include "../src/SingleLinkList.hpp"

void allocateNSLL(SingleLinkList<int> &sll, int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        sll.push(arr[i]);
    }
}

void allocateNDLL(DoubleLinkList<int> &dll, int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        dll.push(arr[i]);
    }
}

void allocateNCSLL(CircularLinkList<int> &csll, int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        csll.insert(arr[i], i);
    }
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};

    DoubleLinkList<int> dll;
    allocateNDLL(dll, arr, 5);
    dll.display();
    SingleLinkList<int> sll;
    allocateNSLL(sll, arr, 5);
    sll.display();
    CircularLinkList<int> csll;
    allocateNCSLL(csll, arr, 5);
    csll.display();

    return 0;
}