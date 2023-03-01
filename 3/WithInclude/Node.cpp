#include "Node.h"

int Node::getData()
{
  return data;
}

void Node::setData(int data)
{
  this->data = data;
}

/* NodeWithNext *NodeWithNext::getNext()
{
  return this->next;
}

void NodeWithNext::setNext(NodeWithNext *next)
{
  this->next = dynamic_cast<NodeWithNext *>(next);
}

NodeWithPrev *NodeWithPrev::getPrev()
{
  return this->prev;
}

void NodeWithPrev::setPrev(NodeWithPrev *prev)
{
  this->prev = dynamic_cast<NodeWithPrev *>(prev);
}
 */