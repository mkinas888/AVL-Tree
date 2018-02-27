#include "TreeAVL.hh"

int TreeAVL::treeHeight (NodeAVL *p) {
    if(p ==  NULL) { //if null there is no tree
        return -1;
    }
    // 
    int max = (treeHeight(p->leftSibling) > treeHeight(p->rightSibling) ? treeHeight(p->leftSibling) : treeHeight(p->rightSibling));
    return max + 1; 
}

void TreeAVL::setBf (NodeAVL *p) {
    p->bf = treeHeight(p->rightSibling) - treeHeight(p->leftSibling);
}

void TreeAVL::restoreBalance (NodeAVL *p) {
    setBf(p);
    if (p->bf == 2) {
        //TODO determine when rotate right when left
    } else if (p->bf == -2) {
        //TODO same as above
    }
    if (p->parent != NULL) {
        restoreBalance(p->parent);
    } else {
        rootNode = p;
    }
}

//TODO implement all rotations, adding and deleting nodes
