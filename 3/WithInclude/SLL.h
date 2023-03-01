#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H
#include "SLLNode.h"

class SinglyLinkedList
{
private:
  SLLNode *head;
  SLLNode *tail;
  int size;

public:
  SinglyLinkedList();

  ~SinglyLinkedList();

  void insertFront(int data);

  void insertBack(int data);

  void removeFront();

  void removeBack();

  void printList();

  bool isEmpty();

  int getSize();
};

#endif
