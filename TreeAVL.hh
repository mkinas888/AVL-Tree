#ifndef TREEAVL_HH
#define TREEAVL_HH

#include <iostream>
#include "NodeAVL.hh"

class TreeAVL
{
  private:
    NodeAVL *rootNode;
    NodeAVL rotateRR(NodeAVL *p); // all kinds of rotations needed to rebalance node
    NodeAVL rotateLL(NodeAVL *p); // when new one is added
    NodeAVL rotateRL(NodeAVL *p);
    NodeAVL rotateLR(NodeAVL *p);

    int treeHeight(NodeAVL *p);
    void setBf(NodeAVL *p);          // setting balance factor when new node is added to tree
    void restoreBalance(NodeAVL *p); // rebalancing tree when needed using rotations

  public:
    TreeAVL() : rootNode(NULL) {}
    ~TreeAVL()
    {
        delete rootNode;
    }
    void addNode(float value);
    void deleteNode(float value);
};

#endif