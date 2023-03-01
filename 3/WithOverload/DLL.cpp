#include <iostream>
#include "DLL.h"
#include "DLLNode.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
  while (head != nullptr)
  {
    DLLNode *temp = head;
    head = head->getNext();
    delete temp;
  }
}

void DoublyLinkedList::insertFront(int data)
{
  DLLNode *newNode = new DLLNode(data);
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

void DoublyLinkedList::insertBack(int data)
{
  DLLNode *newNode = new DLLNode(data);
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

void DoublyLinkedList::removeFront()
{
  if (isEmpty())
  {
    cerr << "List is empty\n";
    return;
  }
  DLLNode *temp = head;
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

void DoublyLinkedList::removeBack()
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
    DLLNode *temp = tail;
    tail = tail->getPrev();
    delete temp;
  }

  size--;
}

void DoublyLinkedList::printList()
{
  cout << "Elements: ";
  DLLNode *current = head;
  while (current != nullptr)
  {
    cout << current->getData() << " ";
    current = current->getNext();
  }
  cout << endl;
}

bool DoublyLinkedList::isEmpty()
{
  return head == nullptr;
}

int DoublyLinkedList::getSize()
{
  return size;
}
