#include "SLLNode.h"

SLLNode::SLLNode(int data)
{
  this->data = data;
  this->next = nullptr;
};

SLLNode *SLLNode::getNext()
{
  return this->next;
};

void SLLNode::setNext(NodeWithNext *next)
{
  this->next = dynamic_cast<SLLNode *>(next);
}