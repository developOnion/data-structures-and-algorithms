#include <iostream>

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
class LinkList
{
private:
  int length;
  NodeSLL<T> *head;
  NodeSLL<T> *tail;

public:
  LinkList()
  {
    this->head = this->tail = nullptr;
    this->length = 0;
  }

  ~LinkList()
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
  void deleteAtIndex(int idx);
  void deleteFromBack();
  void deleteFromFront();
  void insertAtIndex(T val, int idx);
  void insertAtBack(T val);
  void insertAtFront(T val);
  void display();
};

int main(void)
{
  LinkList<int> ll;

  return 0;
}

template <typename T>
int LinkList<T>::size()
{
  return this->length;
}

template <typename T>
void LinkList<T>::display()
{
  NodeSLL<T> *curr = this->head;

  while (curr != nullptr)
  {
    std::cout << curr->data << " ";
    curr = curr->next;
  }
  std::cout << "\n";

  if (!this->head)
  {
    std::cout << "LinkList is Empty.";
  }
  else
  {
    std::cout << "head: " << this->head->data
              << " tail: " << this->tail->data
              << " size: " << this->length << "\n";
  }
}

template <typename T>
void LinkList<T>::insertAtFront(T val)
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
void LinkList<T>::insertAtBack(T val)
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
void LinkList<T>::insertAtIndex(T val, int idx)
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
void LinkList<T>::deleteFromFront()
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
void LinkList<T>::deleteFromBack()
{
  if (this->head == nullptr)
    return;

  if (this->head->next == nullptr)
  {
    NodeSLL<T> *tmp = this->head;
    this->head = this->tail = nullptr;
    delete tmp;
    this->length--;
    return;
  }

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

// 1 2 3 4 5

template <typename T>
void LinkList<T>::deleteAtIndex(int idx)
{
  if (idx < 1 || idx > this->length)
    return;

  if (idx == 1)
  {
    NodeSLL<T> *tmp = this->head;
    this->head = this->head->next;
    delete tmp;
    this->length--;

    if (this->head == nullptr)
    {
      this->tail = nullptr;
    }
  }

  NodeSLL<T> *curr = this->head;
  NodeSLL<T> *prev = NULL;

  for (int i = 0; i < idx - 1; ++i)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr->next == nullptr)
  {
    tail = prev;
  }

  NodeSLL<T> *tmp = curr;
  prev->next = curr->next;
  delete tmp;
  this->length--;
}

template <typename T>
void LinkList<T>::swap(int idx1, int idx2)
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
bool LinkList<T>::search(T val)
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
