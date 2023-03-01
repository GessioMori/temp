#include "Queue.h"
#include "SLL.h"

Queue::Queue()
{
  list = new SinglyLinkedList();
}

Queue::~Queue()
{
  delete list;
}

void Queue::push(int data)
{
  list->insertBack(data);
}

void Queue::pop()
{
  list->removeFront();
}

bool Queue::isEmpty()
{
  return list->isEmpty();
}

void Queue::printQueue()
{
  list->printList();
}
