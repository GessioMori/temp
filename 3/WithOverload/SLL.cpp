#include <iostream>
#include "SLL.h"
#include "SLLNode.h"

using namespace std;

SLLNode operator+(SLLNode &first, SLLNode &second)
{
  first.setNext(&second);
  return first;
};

SinglyLinkedList::SinglyLinkedList()
{
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
  while (head != nullptr)
  {
    SLLNode *temp = head;
    head = head->getNext();
    delete temp;
  }
}

void SinglyLinkedList::insertFront(int data)
{
  SLLNode *newNode = new SLLNode(data);
  if (isEmpty())
  {
    head = tail = newNode;
  }
  else
  {
    *newNode + *head;
    head = newNode;
  }
  size++;
}

void SinglyLinkedList::insertBack(int data)
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

void SinglyLinkedList::removeFront()
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

void SinglyLinkedList::removeBack()
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

void SinglyLinkedList::printList()
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

bool SinglyLinkedList::isEmpty()
{
  return head == nullptr;
}

int SinglyLinkedList::getSize()
{
  return size;
}
