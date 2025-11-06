#include <iostream>
#include <stdexcept>

#include "../header/DoubleLinkList.h"

template <typename T>
int DoubleLinkList<T>::size()
{
    return this->length;
}

template <typename T>
void DoubleLinkList<T>::display()
{
    NodeDLL<T> *curr = this->head;

    std::cout << "DLL: ";
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
    std::cout << "length: " << this->length << "\n";
}

template <typename T>
void DoubleLinkList<T>::insert(T val, int index)
{
    if (index < 0 || index > this->length)
        throw std::out_of_range("Index out of bound");

    NodeDLL<T> *tmp = new NodeDLL<T>(val);

    if (index == 0)
    {
        tmp->next = this->head;

        if (this->head)
        {
            this->head->prev = tmp;
        }
        else
        {
            this->tail = tmp;
        }

        this->head = tmp;
    }
    else if (index == this->length)
    {
        tmp->prev = this->tail;
        this->tail->next = tmp;
        this->tail = tmp;
    }
    else
    {
        NodeDLL<T> *curr = this->head;

        for (int i = 0; i < index - 1; ++i)
        {
            curr = curr->next;
        }

        tmp->next = curr->next;
        tmp->prev = curr;
        curr->next->prev = tmp;
        curr->next = tmp;
    }

    this->length++;
}

template <typename T>
void DoubleLinkList<T>::remove(int index)
{
    if (index < 0 || index >= this->length)
        throw std::out_of_range("Index out of bound");

    NodeDLL<T> *tmp = this->head;

    if (index == 0)
    {
        this->head = this->head->next;
        if (this->head)
        {
            this->head->prev = nullptr;
        }
        else
        {
            this->tail = nullptr;
        }
    }
    else if (index == this->length - 1)
    {
        tmp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
    }
    else
    {
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    delete tmp;
    this->length--;
}

template <typename T>
void DoubleLinkList<T>::push(T val)
{
    NodeDLL<T> *tmp = new NodeDLL<T>(val);

    tmp->prev = this->tail;
    if (this->tail)
    {
        this->tail->next = tmp;
    }
    else
    {
        this->head = tmp;
    }

    this->tail = tmp;
    this->length++;
}

template <typename T>
void DoubleLinkList<T>::pop()
{
    if (this->length == 0)
        return;

    NodeDLL<T> *tmp = this->tail;
    this->tail = this->tail->prev;
    if (this->tail)
    {
        this->tail->next = nullptr;
    }
    else
    {
        this->head = nullptr;
    }

    delete tmp;
    this->length--;
}

template <typename T>
void DoubleLinkList<T>::shift()
{
    if (this->length == 0)
        return;

    NodeDLL<T> *tmp = this->head;

    this->head = this->head->next;
    if (this->head)
    {
        this->head->prev = nullptr;
    }
    else
    {
        this->tail = nullptr;
    }

    this->length--;
    delete tmp;
}

template <typename T>
void DoubleLinkList<T>::unshift(T val)
{
    NodeDLL<T> *tmp = new NodeDLL<T>(val);

    tmp->next = this->head;

    if (this->head)
    {
        this->head->prev = tmp;
    }
    else
    {
        this->tail = tmp;
    }

    this->head = tmp;
    this->length++;
}

template class DoubleLinkList<int>;
template class NodeDLL<int>;

template class DoubleLinkList<double>;
template class NodeDLL<double>;

template class DoubleLinkList<char>;
template class NodeDLL<char>;

template class DoubleLinkList<std::string>;
template class NodeDLL<std::string>;
