#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "DLLNode.h"

class DoublyLinkedList
{
private:
  DLLNode *head;
  DLLNode *tail;
  int size;

public:
  DoublyLinkedList();

  ~DoublyLinkedList();

  void insertFront(int data);

  void insertBack(int data);

  void removeFront();

  void removeBack();

  void printList();

  bool isEmpty();

  int getSize();
};

#endif
