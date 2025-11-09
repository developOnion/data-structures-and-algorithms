#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class NodeCSLL
{
public:
    T data;
    NodeCSLL *next;

    NodeCSLL(T val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

template <typename T>
class CircularLinkList
{
private:
    int length;
    NodeCSLL<T> *head;
    NodeCSLL<T> *tail;

    void RdisplayHelper(NodeCSLL<T> *curr);

public:
    CircularLinkList()
    {
        this->head = this->tail = nullptr;
        this->length = 0;
    }

    ~CircularLinkList()
    {
        if (this->head == nullptr)
            return;

        NodeCSLL<T> *curr = this->head;
        NodeCSLL<T> *next;

        do
        {
            next = curr->next;
            delete curr;
            curr = next;
        } while (curr != this->head);

        this->head = nullptr;
    }

    int size();
    void display();
    void Rdisplay();
    void insert(T val, int index);
    void remove(int index);
    void remove(NodeCSLL<T> *pred);
    NodeCSLL<T> *traverseByN(int n);
    void rotate(int k);
};

template <typename T>
void CircularLinkList<T>::RdisplayHelper(NodeCSLL<T> *curr)
{
    static bool flag = false;

    if (curr != this->head || !flag)
    {
        flag = true;
        std::cout << curr->data << " ";
        RdisplayHelper(curr->next);
    }

    flag = false;
}

template <typename T>
int CircularLinkList<T>::size()
{
    return this->length;
}

template <typename T>
void CircularLinkList<T>::display()
{
    if (this->head == nullptr)
        return;

    NodeCSLL<T> *curr = this->head;

    std::cout << "CSLL: ";
    do
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != this->head);
    std::cout << "\n";
    std::cout << "length: " << this->length << "\n";
}

template <typename T>
void CircularLinkList<T>::Rdisplay()
{
    if (this->head == nullptr)
        return;

    RdisplayHelper(this->head);
}

template <typename T>
void CircularLinkList<T>::insert(T val, int index)
{
    if (index < 0 || index > this->length)
        throw std::out_of_range("Index out of bound");

    NodeCSLL<T> *tmp = new NodeCSLL<T>(val);
    NodeCSLL<T> *curr = this->head;

    if (index == 0)
    {
        if (this->head == nullptr)
        {
            this->head = this->tail = tmp;
            tmp->next = this->head;
        }
        else
        {
            tmp->next = this->head;
            this->tail->next = tmp;
            this->head = tmp;
        }
    }
    else if (index == this->length)
    {
        this->tail->next = tmp;
        this->tail = tmp;
        this->tail->next = this->head;
    }
    else
    {
        for (int i = 0; i < index - 1; ++i)
        {
            curr = curr->next;
        }

        tmp->next = curr->next;
        curr->next = tmp;
    }

    this->length++;
}

template <typename T>
void CircularLinkList<T>::remove(int index)
{
    if (index < 0 || index >= this->length || this->length == 0)
        throw std::out_of_range("Index out of bound");

    NodeCSLL<T> *curr = this->head;
    NodeCSLL<T> *tmp = this->head;

    if (index == 0)
    {
        if (this->length == 1)
        {
            this->head = this->tail = nullptr;
        }
        else
        {
            this->tail->next = this->head->next;
            this->head = this->head->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; ++i)
        {
            curr = curr->next;
        }

        tmp = curr->next;
        curr->next = tmp->next;

        if (curr->next == this->head)
        {
            this->tail = curr;
        }
    }

    delete tmp;
    this->length--;
}

template <typename T>
void CircularLinkList<T>::remove(NodeCSLL<T> *pred)
{
    if (this->length == 0)
        return;

    NodeCSLL<T> *curr = pred->next;

    if (curr == pred)
    {
        this->head = this->tail = nullptr;
    }
    else if (curr == this->head)
    {
        pred->next = curr->next;
        this->head = this->head->next;
    }
    else
    {
        pred->next = curr->next;
        if (curr->next == this->head)
        {
            this->tail = pred;
        }
    }

    delete curr;
    this->length--;
}

template <typename T>
void CircularLinkList<T>::rotate(int k)
{
    if (this->length == 0 || k <= 0)
        return;

    k = k % this->length;
    if (k == 0)
        return;

    NodeCSLL<T> *curr = this->traverseByN(this->length - k - 1);
    this->head = curr->next;
    this->tail = curr;
}

template <typename T>
NodeCSLL<T> *CircularLinkList<T>::traverseByN(int n)
{
    if (this->length == 0 || n < 1)
        return nullptr;

    NodeCSLL<T> *curr = this->head;
    for (int i = 0; i < n; ++i)
    {
        curr = curr->next;
    }

    return curr;
}
