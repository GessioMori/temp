#ifndef QUEUE_H
#define QUEUE_H
#include "SLL.h"

class Queue
{
private:
  SinglyLinkedList *list;

public:
  Queue();

  ~Queue();

  void push(int data);

  void pop();

  bool isEmpty();

  void printQueue();
};

#endif
