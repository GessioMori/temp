#include <iostream>

using namespace std;

class Node
{
public:
  virtual int getData() = 0;
  virtual void setData(int data) = 0;
  virtual Node *getNext() = 0;
  virtual void setNext(Node *next) = 0;
  virtual Node *getPrev() = 0;
  virtual void setPrev(Node *prev) = 0;
};

class SLLNode : public Node
{
private:
  int data;
  SLLNode *next;

public:
  SLLNode(int data)
  {
    this->data = data;
    this->next = nullptr;
  }

  int getData()
  {
    return data;
  }

  void setData(int data)
  {
    this->data = data;
  }

  SLLNode *getNext()
  {
    return next;
  }

  void setNext(Node *next)
  {
    this->next = dynamic_cast<SLLNode *>(next);
  }

  SLLNode *getPrev()
  {
    return nullptr;
  }

  void setPrev(Node *prev)
  {
    return;
  }
};

class SinglyLinkedList
{
private:
  SLLNode *head;
  SLLNode *tail;
  int size;

public:
  SinglyLinkedList()
  {
    this->head = nullptr;
  }

  ~SinglyLinkedList()
  {
    while (head != nullptr)
    {
      SLLNode *temp = head;
      head = head->getNext();
      delete temp;
    }
  }

  void insertFront(int data)
  {
    SLLNode *newNode = new SLLNode(data);
    if (isEmpty())
    {
      head = tail = newNode;
    }
    else
    {
      newNode->setNext(head);
      head = newNode;
    }
    size++;
  }

  void insertBack(int data)
  {
    SLLNode *newNode = new SLLNode(data);
    if (isEmpty())
    {
      head = tail = newNode;
    }
    else
    {
      tail->setNext(newNode);
      tail = newNode;
    }
    size++;
  }

  void removeFront()
  {
    if (isEmpty())
    {
      cerr << "List is empty\n";
      return;
    }
    SLLNode *temp = head;
    if (head == tail)
    {
      head = tail = nullptr;
    }
    else
    {
      head = head->getNext();
    }
    delete temp;
    size--;
  }

  void removeBack()
  {
    if (isEmpty())
    {
      cerr << "List is empty\n";
      return;
    }

    if (head == tail)
    {
      delete head;
      head = tail = nullptr;
    }
    else
    {
      SLLNode *curr = head;
      while (curr->getNext()->getNext() != nullptr)
      {
        curr = curr->getNext();
      }
      delete curr->getNext();
      curr->setNext(nullptr);
      tail = curr;
    }

    size--;
  }

  void printList()
  {
    cout << "Elements: ";
    SLLNode *current = head;
    while (current != nullptr)
    {
      cout << current->getData() << " ";
      current = current->getNext();
    }
    cout << endl;
  }

  bool isEmpty()
  {
    return head == nullptr;
  }

  int getSize()
  {
    return size;
  }
};

class Queue
{
private:
  SinglyLinkedList *list;

public:
  Queue()
  {
    list = new SinglyLinkedList();
  }

  ~Queue()
  {
    delete list;
  }

  void push(int data)
  {
    list->insertBack(data);
  }

  void pop()
  {
    list->removeFront();
  }

  bool isEmpty()
  {
    return list->isEmpty();
  }

  void printQueue()
  {
    list->printList();
  }
};

int main()
{

  system("clear");

  Queue *myQueue = new Queue();
  int choice, element;

  do
  {
    cout << "1. Push element\n"
         << "2. Pop element\n"
         << "3. Check if queue is empty\n"
         << "4. Print stack\n"
         << "0. Quit\n";

    cin >> choice;

    system("clear");

    switch (choice)
    {
    case 1:
      cout << "Enter element to push: ";
      cin >> element;
      myQueue->push(element);
      break;

    case 2:
      myQueue->pop();
      break;

    case 3:
      if (myQueue->isEmpty())
      {
        cout << "Queue is empty\n";
      }
      else
      {
        cout << "Queue is not empty\n";
      }
      break;

    case 4:
      if (myQueue->isEmpty())
      {
        cout << "Queue is empty\n";
      }
      else
      {
        myQueue->printQueue();
      }
      break;

    case 0:
      cout << "Exiting program\n";
      break;

    default:
      cout << "Invalid choice, try again\n";
    }

    cout << endl;

  } while (choice != 0);

  return 0;
}
