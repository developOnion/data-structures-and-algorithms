#pragma once

#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node() {}

    Node(T val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    int length;

public:
    Queue()
    {
        this->front = this->rear = nullptr;
        this->length = 0;
    }

    ~Queue()
    {
        Node<T> *next;
        Node<T> *curr = this->front;
        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int size() const
    {
        return this->length;
    }

    void enqueue(const T val)
    {
        Node<T> *tmp = new Node<T>(val);

        if (this->front == nullptr)
        {
            this->front = this->rear = tmp;
        }
        else
        {
            this->rear->next = tmp;
            this->rear = tmp;
        }

        this->length++;
    }

    T dequeue()
    {
        T val = T();

        if (this->front == nullptr)
        {
            std::cout << "Queue is empty.\n";
        }
        else
        {
            Node<T> *tmp = this->front;
            val = tmp->data;
            this->front = this->front->next;

            if (!this->front)
            {
                this->rear = nullptr;
            }

            delete tmp;
            this->length--;
        }

        return val;
    }

    bool isEmpty() const
    {
        return this->front == nullptr;
    }

    T peek() const
    {
        return this->front ? this->front->data : T();
    }
};