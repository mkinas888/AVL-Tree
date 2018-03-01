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

NodeAVL* TreeAVL::rotateLL (NodeAVL *p) {
    NodeAVL *r = p->rightSibling;
    r->parent = p->parent;
    p->rightSibling = r->leftSibling;
    if( p->rightSibling != NULL) {
        p->rightSibling->parent = p;
    }
    r->leftSibling = p;
    p->parent = r;
    if (r->parent != NULL) {
        if (r->parent->rightSibling == p) {
            r->parent->rightSibling = r;
        }
        else {
            r->parent->leftSibling = r;
        }
    }
    setBf(r);
    setBf(p);
    return r;
}

NodeAVL* TreeAVL::rotateRR (NodeAVL *p) {
    NodeAVL *r = p->leftSibling;
    r->parent = p->parent;
    p->leftSibling = r->rightSibling;
    if (p->leftSibling != NULL) {
        p->leftSibling->parent = p;    
    }
    r->rightSibling = p;
    p->parent = r;
    if (r->parent != NULL) {
        if (r->parent->rightSibling == p) {
            r->parent->rightSibling = r;
        }
        else {
            r->parent->leftSibling = r;
        }
    }
    setBf(r);
    setBf(p);
    return r;
}

NodeAVL* TreeAVL::rotateLR (NodeAVL *p) {
    p->leftSibling = rotateLL(p->leftSibling);
    return rotateRR(p);
}

NodeAVL* TreeAVL::rotateRL (NodeAVL *p) {
    p->rightSibling = rotateRR(p->rightSibling);
    return rotateLL(p);
}

void TreeAVL::restoreBalance (NodeAVL *p) {
    setBf(p);
    if (p->bf == 2) {
        if (p->rightSibling->bf == -1) {
            rotateLR(p);
        } else {
            rotateLL(p);
        }
    } else if (p->bf == -2) {
        if (p->leftSibling->bf == 1) {
            rotateRL(p);
        } else {
            rotateRR(p);
        }
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
