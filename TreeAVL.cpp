#include "TreeAVL.hh"

int TreeAVL::treeHeight (NodeAVL *p) {
    if(p ==  NULL) { //if null there is no tree
        return -1;
    }
    // determine if left or right subtree is higher and get this height
    int max = (treeHeight(p->leftSibling) > treeHeight(p->rightSibling) ? treeHeight(p->leftSibling) : treeHeight(p->rightSibling));
    return max + 1; 
}

void TreeAVL::setBf (NodeAVL *p) {
    p->bf = treeHeight(p->rightSibling) - treeHeight(p->leftSibling);
}

void TreeAVL::restoreBalance (NodeAVL *p) {
    setBf(p);
    if (p->bf == 2) {
        //TODO determine when rotate RR and when RL
    } else if (p->bf == -2) {
        //TODO determine when rotate LL and when LR
    }
    if (p->parent != NULL) {
        restoreBalance(p->parent);
    } else {
        rootNode = p;
    }
}

void TreeAVL::printNode (NodeAVL *p) {
    if (p == NULL) {
        std::cout << "Tree is empty!" << std::endl;
    } else {
        std::cout << p->value << std::endl;
    }
}

//TODO implement all rotations, adding and deleting nodes
