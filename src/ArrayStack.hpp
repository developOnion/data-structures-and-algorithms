#pragma once

template <typename T>
class ArrayStack
{
private:
    int size;
    int top;
    T *stack;

public:
    ArrayStack(int size)
    {
        this->size = size;
        this->top = -1;
        stack = new T[size];
    }

    ~ArrayStack()
    {
        delete[] this->stack;
    }

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top == this->size - 1;
    }

    T peek()
    {
        return (this->isEmpty()) ? T() : this->stack[this->top];
    }

    void push(T val)
    {
        if (this->isFull())
        {
            std::cout << "Error: Stack Overflow\n";
        }
        else
        {
            this->top++;
            this->stack[top] = val;
        }
    }

    T pop()
    {
        T val = T();

        if (this->isEmpty())
        {
            std::cout << "Error: Stack Underflow\n";
        }
        else
        {
            val = this->stack[this->top];
            this->stack[this->top] = T();
            this->top--;
        }

        return val;
    }
};