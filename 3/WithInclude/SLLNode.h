#ifndef SLLNODE_H
#define SLLNODE_H

#include "Node.h"

class SLLNode : public Node, public NodeWithNext
{
private:
  SLLNode *next;

public:
  SLLNode(int data);

  SLLNode *getNext() override;
  void setNext(NodeWithNext *next) override;
};

#endif
