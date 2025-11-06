#pragma once

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
