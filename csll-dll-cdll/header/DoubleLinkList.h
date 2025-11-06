#pragma once

template <typename T>
class NodeDLL
{
public:
    T data;
    NodeDLL *next;
    NodeDLL *prev;

    NodeDLL(T val)
    {
        this->data = val;
        this->next = this->prev = nullptr;
    }
};

template <typename T>
class DoubleLinkList
{
private:
    int length;
    NodeDLL<T> *head;
    NodeDLL<T> *tail;

public:
    DoubleLinkList()
    {
        this->length = 0;
        this->head = this->tail = nullptr;
    }

    ~DoubleLinkList()
    {
        NodeDLL<T> *curr = this->head;
        NodeDLL<T> *next;

        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }

        this->head = this->tail = nullptr;
    }

    // getter
    int size();

    void display();
    void insert(T val, int index);
    void remove(int index);
    void push(T val);
    void pop();
    void shift();
    void unshift(T val);
};
