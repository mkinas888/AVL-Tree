#ifndef TREEAVL_HH
#define TREEAVL_HH

#include <iostream>
#include <string>
#include "NodeAVL.hh"

class TreeAVL
{
  public:
    NodeAVL *rootNode;
    NodeAVL* rotateRR(NodeAVL *p); // all kinds of rotations needed to rebalance node
    NodeAVL* rotateLL(NodeAVL *p); // when new one is added
    NodeAVL* rotateRL(NodeAVL *p);
    NodeAVL* rotateLR(NodeAVL *p);
    NodeAVL* searchMinimum(NodeAVL *p); // returns node with the least value


    int treeHeight(NodeAVL *p);
    void setBf(NodeAVL *p);                  // setting balance factor when new node is added to tree
    void restoreBalanceFromRoot(NodeAVL *p); // rebalancing tree when needed using rotations
    void restoreBalanceFromLeaf(NodeAVL *p); //rebalance after adding 
    void printNode (NodeAVL *p);             // print custom node value 

    TreeAVL() : rootNode(NULL) {}
    ~TreeAVL()
    {
        delete rootNode;
    }
    void addNode(NodeAVL *parentNode, float value);         // adding new node
    void addAndRebalance(NodeAVL *parentNode, float value); //add with rebalance function
    void deleteNode(float value);                           // deleting node by value
    /* !!! Code of this function was taken from site:http://eduinf.waw.pl/inf/alg/001_search/0119.php#P4 */
    void printBT(std::string sp, std::string sn, NodeAVL * v);
};

#endif