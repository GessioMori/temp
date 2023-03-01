#ifndef STACK_H
#define STACK_H
#include "SLL.h"

class Stack
{
private:
  SinglyLinkedList *list;

public:
  Stack();

  ~Stack();

  void push(int data);

  void pop();

  bool isEmpty();

  void printStack();
};

#endif
