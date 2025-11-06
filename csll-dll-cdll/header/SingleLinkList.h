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