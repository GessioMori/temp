#ifndef NODE_H
#define NODE_H

class Node
{
protected:
  int data;

public:
  int getData();
  void setData(int data);
};

class NodeWithNext
{
protected:
  NodeWithNext *next;

public:
  virtual NodeWithNext *getNext() = 0;
  virtual void setNext(NodeWithNext *next) = 0;
};

class NodeWithPrev
{
protected:
  NodeWithPrev *prev;

public:
  virtual NodeWithPrev *getPrev() = 0;
  virtual void setPrev(NodeWithPrev *prev) = 0;
};

#endif
