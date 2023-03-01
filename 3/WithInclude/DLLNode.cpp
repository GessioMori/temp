#include "DLLNode.h"

DLLNode::DLLNode(int data)
{
  this->data = data;
  this->next = nullptr;
};

DLLNode *DLLNode::getNext()
{
  return this->next;
};

void DLLNode::setNext(NodeWithNext *next)
{
  this->next = dynamic_cast<DLLNode *>(next);
}

DLLNode *DLLNode::getPrev()
{
  return this->prev;
};

void DLLNode::setPrev(NodeWithPrev *prev)
{
  this->prev = dynamic_cast<DLLNode *>(prev);
}