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

int main()
{

  system("clear");

  SinglyLinkedList *myList = new SinglyLinkedList;
  int choice, data;

  do
  {
    cout << "1. Insert at the front\n"
         << "2. Insert at the back\n"
         << "3. Remove from the front\n"
         << "4. Remove from the back\n"
         << "5. Print the list\n"
         << "0. Exit\n";

    cin >> choice;

    system("clear");

    switch (choice)
    {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      myList->insertFront(data);
      break;

    case 2:
      cout << "Enter data: ";
      cin >> data;
      myList->insertBack(data);
      break;

    case 3:
      myList->removeFront();
      break;

    case 4:
      myList->removeBack();
      break;

    case 5:
      if (myList->isEmpty())
      {
        cout << "List is empty\n";
      }
      else
      {
        myList->printList();
      }
      break;
      break;

    case 0:
      cout << "Exiting program\n";
      break;

    default:
      cout << "Invalid choice. Please try again.\n";
      break;
    }

    cout << endl;
  } while (choice != 0);

  return 0;
}
