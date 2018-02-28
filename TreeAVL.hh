#ifndef TREEAVL_HH
#define TREEAVL_HH

#include <iostream>
#include "NodeAVL.hh"

class TreeAVL
{
  public:
    NodeAVL *rootNode;
    NodeAVL rotateRR(NodeAVL *p); // all kinds of rotations needed to rebalance node
    NodeAVL rotateLL(NodeAVL *p); // when new one is added
    NodeAVL rotateRL(NodeAVL *p);
    NodeAVL rotateLR(NodeAVL *p);

    int treeHeight(NodeAVL *p);
    void setBf(NodeAVL *p);          // setting balance factor when new node is added to tree
    void restoreBalance(NodeAVL *p); // rebalancing tree when needed using rotations
    void printNode (NodeAVL *p);   // print custome node value 

    TreeAVL() : rootNode(NULL) {}
    ~TreeAVL()
    {
        delete rootNode;
    }
    void addNode(NodeAVL *parentNode, float value);
    void deleteNode(float value);
};

#endif