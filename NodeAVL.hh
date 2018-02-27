#ifndef NODEAVL_HH
#define NODEAVL_HH

#include <iostream>

class NodeAVL
{
public:
  NodeAVL *parent;                     //pointer to parent of node
  NodeAVL *leftSibling, *rightSibling; //pointers to node's siblings
  int bf;                              //balance factor of node
  float value;

  NodeAVL(NodeAVL *p, float v) : parent(p), value(v), bf(0), leftSibling(NULL), rightSibling(NULL) {}
  ~NodeAVL()
  {
    delete rightSibling;
    delete leftSibling;
  }
};

#endif