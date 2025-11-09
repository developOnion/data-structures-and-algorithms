#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class NodeSLL
{
public:
    T data;
    NodeSLL *next;

    NodeSLL(T val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

template <typename T>
class SingleLinkList
{
private:
    int length;
    NodeSLL<T> *head;
    NodeSLL<T> *tail;

public:
    SingleLinkList()
    {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    ~SingleLinkList()
    {
        NodeSLL<T> *curr = this->head;
        NodeSLL<T> *next;

        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
        this->head = this->tail = next = nullptr;
    }

    // getter
    int size();

    bool search(T val);
    void swap(int idx1, int idx2);
    void remove(int idx);
    void pop();
    void shift();
    void insert(T val, int idx);
    void push(T val);
    void unshift(T val);
    void display();
    NodeSLL<T> *ManualtraverseByN(int n);
    void rotate(int k);
};

template <typename T>
int SingleLinkList<T>::size()
{
    return this->length;
}

template <typename T>
void SingleLinkList<T>::display()
{
    NodeSLL<T> *curr = this->head;

    std::cout << "SLL: ";
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
    std::cout << "length: " << this->length << "\n";
}

template <typename T>
void SingleLinkList<T>::unshift(T val)
{
    NodeSLL<T> *newNode = new NodeSLL<T>(val);
    newNode->next = this->head;
    this->head = newNode;
    this->length++;

    if (this->tail == nullptr)
    {
        this->tail = this->head;
    }
}

template <typename T>
void SingleLinkList<T>::push(T val)
{
    NodeSLL<T> *newNode = new NodeSLL<T>(val);

    if (this->head == nullptr)
    {
        this->head = this->tail = newNode;
        this->length++;
        return;
    }

    this->tail->next = newNode;
    this->tail = newNode;
    this->length++;
}

template <typename T>
void SingleLinkList<T>::insert(T val, int idx)
{
    if (idx < 0 || idx > this->length)
        return;

    NodeSLL<T> *newNode = new NodeSLL<T>(val);

    // insertAtIndex in the front
    if (idx == 0)
    {
        newNode->next = this->head;
        this->head = newNode;
        this->length++;

        if (this->tail == nullptr)
        {
            this->tail = this->head;
        }
    }
    else
    {
        NodeSLL<T> *curr = this->head;
        for (int i = 0; i < idx - 1; ++i)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        this->length++;

        // insertAtIndex at the back we need to update tail
        if (newNode->next == nullptr)
        {
            this->tail = newNode;
        }
    }
}

template <typename T>
void SingleLinkList<T>::shift()
{
    if (this->head == nullptr)
        return;

    NodeSLL<T> *tmp = this->head;
    this->head = this->head->next;
    delete tmp;
    this->length--;

    // only one node we set tail null
    if (this->head == nullptr)
    {
        this->tail = nullptr;
    }
}

template <typename T>
void SingleLinkList<T>::pop()
{
    if (this->head == nullptr)
        return;

    if (this->head->next == nullptr)
    {
        NodeSLL<T> *tmp = this->head;
        this->head = this->tail = nullptr;
        delete tmp;
        this->length--;
    }
    else
    {
        NodeSLL<T> *curr = this->head;
        while (curr->next->next != nullptr)
        {
            curr = curr->next;
        }

        NodeSLL<T> *tmp = this->tail;
        this->tail = curr;
        this->tail->next = nullptr;
        delete tmp;
        this->length--;
    }
}

template <typename T>
void SingleLinkList<T>::remove(int idx)
{
    if (idx < 0 || idx >= this->length)
        return;

    if (idx == 0)
    {
        NodeSLL<T> *tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        this->length--;

        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
        return;
    }

    NodeSLL<T> *curr = this->head;
    NodeSLL<T> *prev = nullptr;

    for (int i = 0; i < idx; ++i)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == nullptr)
    {
        this->tail = prev;
    }

    prev->next = curr->next;
    delete curr;
    this->length--;
}

template <typename T>
void SingleLinkList<T>::swap(int idx1, int idx2)
{
    // Invalid cases
    if (idx1 < 1 || idx2 < 1 || idx1 > this->length || idx2 > this->length || idx1 == idx2)
        return;

    // Make idx1 always smaller than idx2
    if (idx1 > idx2)
    {
        int temp = idx1;
        idx1 = idx2;
        idx2 = temp;
    }

    NodeSLL<T> *prev1 = nullptr, *curr1 = this->head;
    NodeSLL<T> *prev2 = nullptr, *curr2 = this->head;

    for (int i = 1; i < idx1; i++)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    for (int i = 1; i < idx2; i++)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    // Handle head updates
    if (idx1 == 1)
    {
        this->head = curr2;
    }
    else
    {
        prev1->next = curr2;
    }

    // Handle tail updates
    if (curr2->next == nullptr)
    {
        this->tail = curr1;
    }

    NodeSLL<T> *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;

    // Handle adjacent nodes case
    if (idx2 - idx1 == 1)
    {
        curr2->next = curr1;
    }
    else
    {
        prev2->next = curr1;
    }
}

template <typename T>
bool SingleLinkList<T>::search(T val)
{
    NodeSLL<T> *curr = this->head;

    while (curr != nullptr)
    {
        if (curr->data == val)
            return true;

        curr = curr->next;
    }

    return false;
}

template <typename T>
NodeSLL<T> *SingleLinkList<T>::ManualtraverseByN(int n)
{
    if (this->length == 0 || n < 1)
        return nullptr;

    NodeSLL<T> *curr = this->head;
    for (int i = 0; i < n; ++i)
    {
        if (curr->next == nullptr)
        {
            curr = this->head;
        }
        else
        {
            curr = curr->next;
        }
    }

    return curr;
}

template <typename T>
void SingleLinkList<T>::rotate(int k)
{
    if (this->length == 0 || k <= 0)
        return;

    k = k % this->length;
    if (k == 0)
        return;

    NodeSLL<T> *curr = this->head;
    for (int i = 0; i < this->length - k - 1; ++i)
    {
        curr = curr->next;
    }
    this->tail->next = this->head;
    this->head = curr->next;
    this->tail = curr;
    this->tail->next = nullptr;
}
