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
class Stack
{
private:
    int size;
    Node<T> *top;

public:
    Stack()
    {
        this->size = 0;
        this->top = nullptr;
    }

    ~Stack()
    {
        Node<T> *next;
        Node<T> *curr = this->top;
        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void toString()
    {
        std::cout << "Size: " << this->size << "\n";

        if (this->top != nullptr)
        {
            std::cout << "Top: " << this->top->data << "\n";
        }
        else
        {
            std::cout << "Top: " << "NULL" << "\n";
        }

        std::cout << "Stack: ";
        Node<T> *curr = this->top;
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << "\n";
    }

    bool isEmpty()
    {
        return this->top == nullptr;
    }

    bool isFull()
    {
        Node<T> *tmp = new (std::nothrow) Node<T>();
        if (tmp == nullptr)
        {
            return true;
        }
        delete tmp;
        return false;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (!newNode)
        {
            std::cout << "Error: Stack Overflow\n";
            return;
        }

        newNode->next = this->top;
        this->top = newNode;
        this->size++;
    }

    T pop()
    {
        T val = T();

        if (this->top == nullptr)
        {
            std::cout << "Error: Stack Underflow\n";
        }
        else
        {
            val = this->top->data;
            Node<T> *tmp = this->top;
            this->top = this->top->next;
            delete tmp;
            this->size--;
        }

        return val;
    }

    // T peek(int index)
    // {
    //     if (index < 0 || index >= this->size)
    //     {
    //         std::cout << "Error: Invalid Index\n";
    //         return T();
    //     }

    //     Node<T> *curr = this->top;
    //     for (int i = 0; i < index; ++i)
    //     {
    //         curr = curr->next;
    //     }

    //     return curr->data;
    // }

    T peek()
    {
        return (this->top == nullptr) ? T() : this->top->data;
    }
};
