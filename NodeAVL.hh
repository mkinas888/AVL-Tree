#ifndef NODEAVL_HH
#define NODEAVL_HH

#include <iostream>

class NodeAVL
{
  private:
    NodeAVL *parent;                     //pointer to parent of node
    NodeAVL *leftSibling, *rightSibling; //pointers to node's siblings
    int bf;                              //balance factor of node
    float value;

  public:
    NodeAVL(NodeAVL *p, int balance, float v) : parent(p), value(v), bf(balance), leftSibling(NULL), rightSibling(NULL) {}
    ~NodeAVL()
    {
        delete rightSibling;
        delete leftSibling;
    }
};

#endif