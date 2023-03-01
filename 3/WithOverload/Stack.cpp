#include "Stack.h"
#include "SLL.h"

Stack::Stack()
{
  list = new SinglyLinkedList();
}

Stack::~Stack()
{
  delete list;
}

void Stack::push(int data)
{
  list->insertFront(data);
}

void Stack::pop()
{
  list->removeFront();
}

bool Stack::isEmpty()
{
  return list->isEmpty();
}

void Stack::printStack()
{
  list->printList();
}
