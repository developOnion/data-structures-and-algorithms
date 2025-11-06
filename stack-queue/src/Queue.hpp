#pragma once

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

public:
    Queue()
    {
        this->front = this->rear = nullptr;
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

    void toString()
    {
        if (this->front)
        {
            std::cout << "Front: " << this->front->data << "\n";
        }
        else
        {
            std::cout << "Front: NULL\n";
        }

        if (this->rear)
        {
            std::cout << "Rear: " << this->rear->data << "\n";
        }
        else
        {
            std::cout << "Rear: NULL\n";
        }

        std::cout << "Queue: ";
        Node<T> *curr = this->front;
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    void enqueue(T val)
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
    }

    T dequeue()
    {
        T val = T();

        if (this->front == nullptr)
        {
            std::cout << "Error: Empty Queue\n";
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
        }

        return val;
    }

    bool isEmpty()
    {
        return this->front == nullptr;
    }

    T peek()
    {
        return (this->front == nullptr) ? T() : this->front->data;
    }
};