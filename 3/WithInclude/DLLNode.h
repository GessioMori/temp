#ifndef DLLNODE_H
#define DLLNODE_H

#include "Node.h"

class DLLNode : public Node, public NodeWithNext, public NodeWithPrev
{
private:
  DLLNode *next;
  DLLNode *prev;

public:
  DLLNode(int data);

  DLLNode *getNext() override;
  void setNext(NodeWithNext *next) override;
  DLLNode *getPrev() override;
  void setPrev(NodeWithPrev *prev) override;
};

#endif
