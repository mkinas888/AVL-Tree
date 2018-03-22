#include "TreeAVL.hh"

using namespace std;


int TreeAVL::treeHeight(NodeAVL *p)
{
    //if null there is no tree
    if (p == NULL)
    {
        return -1;
    }
    int left = treeHeight(p->leftSibling);
    int right = treeHeight(p->rightSibling);
    if(left > right)
        return left + 1;
    else if (right > left)
        return right + 1;
    return left + 1;
}

void TreeAVL::setBf(NodeAVL *p)
{
    p->bf = treeHeight(p->rightSibling) - treeHeight(p->leftSibling);
}

NodeAVL *TreeAVL::rotateLL(NodeAVL *p)
{
    /*
    NodeAVL* temp;
	temp = p->rightSibling;
	p->rightSibling = temp->leftSibling;
	temp->leftSibling = p;
	temp->parent = p->parent;
	p = temp;
	if (temp->parent == NULL) {
		rootNode = temp;
	}*/
    
    NodeAVL *r = p->rightSibling;
    r->parent = p->parent;
    p->rightSibling = r->leftSibling;
    if (p->rightSibling != NULL)
    {
        p->rightSibling->parent = p;
    }
    r->leftSibling = p;
    p->parent = r;
    if (r->parent != NULL)
    {
        if (r->parent->rightSibling == p)
        {
            r->parent->rightSibling = r;
        }
        else
        {
            r->parent->leftSibling = r;
        }
    }
    setBf(p);
    //setBf(temp);
    setBf(r);
    return r;
}

NodeAVL *TreeAVL::rotateRR(NodeAVL *p)
{
    /*
    NodeAVL* temp;
	temp = p->leftSibling;
	p->leftSibling = temp->rightSibling;
	temp->rightSibling = p;
	temp->parent = p->parent;
	p = temp;
	if (temp->parent == NULL) {
		rootNode = temp;
	}*/

    NodeAVL *r = p->leftSibling;
    r->parent = p->parent;
    p->leftSibling = r->rightSibling;
    if (p->leftSibling != NULL)
    {
        p->leftSibling->parent = p;
    }
    r->rightSibling = p;
    p->parent = r;
    if (r->parent != NULL)
    {
        if (r->parent->rightSibling == p)
        {
            r->parent->rightSibling = r;
        }
        else
        {
            r->parent->leftSibling = r;
        }
    }
    setBf(r);
    //setBf(temp);
    setBf(p);
    return r;
}

NodeAVL *TreeAVL::rotateLR(NodeAVL *p)
{
    p->leftSibling = rotateLL(p->leftSibling);
    return rotateRR(p);
}

NodeAVL *TreeAVL::rotateRL(NodeAVL *p)
{
    p->rightSibling = rotateRR(p->rightSibling);
    return rotateLL(p);
}

void TreeAVL::restoreBalance(NodeAVL *p)
{
    setBf(p);
    if (p->bf == -2)
    {
        if (treeHeight(p->leftSibling->leftSibling) >= treeHeight(p->leftSibling->rightSibling))
            p = rotateRR(p);
        else
            p = rotateLR(p);
    }
    else if (p->bf == 2) {
        if (treeHeight(p->rightSibling->rightSibling) >= treeHeight(p->rightSibling->leftSibling))
            p = rotateLL(p);
        else
            p = rotateRL(p);
    }
    
    if(p->leftSibling != NULL) {
        if(p->leftSibling->leftSibling != NULL){
            restoreBalance(p->leftSibling->leftSibling);
        }
        else if(p->leftSibling->rightSibling != NULL) {
            restoreBalance(p->leftSibling->rightSibling);
        }
    }
    if(p->rightSibling != NULL) {
        if(p->rightSibling->leftSibling != NULL){
            restoreBalance(p->rightSibling->leftSibling);
        } 
        else if (p->rightSibling->rightSibling) {
            restoreBalance(p->rightSibling->rightSibling);
        }
    }

    
    /*
    if (p->parent != NULL) {
        restoreBalance(p->parent);
    }
    else {
        rootNode = p;
    }*/
}

void TreeAVL::printNode(NodeAVL *p)
{
    if (p == NULL)
    {
        std::cout << "Tree is empty!" << std::endl;
    }
    else
    {
        std::cout << p->value << std::endl;
    }
}

bool TreeAVL::addNode(NodeAVL *parent, float value)
{
    if (rootNode == NULL) {
        rootNode = new NodeAVL(NULL, value);
    }
    else {
        NodeAVL
            *n = rootNode,
            *parent;
 
        while (true) {
            if (n->value == value)
                return false;
 
            parent = n;
 
            bool goLeft = n->value > value;
            n = goLeft ? n->leftSibling : n->rightSibling;
 
            if (n == NULL) {
                if (goLeft) {
                    parent->leftSibling = new NodeAVL(parent, value);
                }
                else {
                    parent->rightSibling = new NodeAVL(parent, value);
                }
 
                //restoreBalance(parent);
                break;
            }
        }
    }
 
    return true;
   /* bool tmp;
    if (rootNode == NULL)
    {
        rootNode = new NodeAVL(NULL, value); //if there's no tree create the root
    }
    else
    {
        NodeAVL *p=rootNode, *parent;
        while(p->value != value)
        {               //repeat until newly added node is found
            parent = p; //go one level down in a tree
            if (p->value > value)
            { //if value of new node is lower then value of p go left
                p->value = tmp;
                p = p->leftSibling;
                tmp = true;
            }
            else
            { //else go right
                p->value = tmp;
                p = p->rightSibling;
            }
            if (p == NULL)
            { //if parent has no children
                if (tmp)
                { //create left or right chlid depending on a value
                    parent->leftSibling = new NodeAVL(parent, value);
                }
                else
                {
                    parent->rightSibling = new NodeAVL(parent, value);
                }
                restoreBalance(parent); //when node is added check bf and rotate if needed
                break;
            }
        }
    }*/
}

NodeAVL *TreeAVL::searchMinimum(NodeAVL *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if (p->leftSibling == NULL)
    {
        return p;
    }
    else {
        searchMinimum(p->leftSibling);
    }
    return p;
}

NodeAVL *TreeAVL::deleteNode(float value)
{

    NodeAVL *deletingNode,
        *parentNode = rootNode,
        *pNode = rootNode,
        *childNode = rootNode;

    if (rootNode == NULL)
    { //there is no tree so nothing can be deleted
        cout << "There is no tree!" << endl;
    }

    while (childNode != NULL)
    {
        parentNode = pNode;
        pNode = childNode;
        if (value < pNode->value)
        {
            childNode = pNode->leftSibling;
        }
        else if (value > pNode->value)
        {
            childNode = pNode->rightSibling;
        }
        else if (value == pNode->value)
        {
            deletingNode = pNode;
        }
    }

    if (deletingNode == NULL)
    {
        std::cout << "There is no node of value:" << value;
    }
    else
    {
        if (pNode->leftSibling == NULL && pNode->rightSibling == NULL)
        {
            delete pNode;
        }
        if (pNode->rightSibling == NULL)
        {
            parentNode->leftSibling = pNode->leftSibling;
            delete pNode;
        }
        if (pNode->leftSibling == NULL)
        {
            parentNode->rightSibling = pNode->rightSibling;
            delete pNode;
        }
        else
        {
            deletingNode = searchMinimum(pNode->rightSibling);
            pNode->value = deletingNode->value;
            pNode->rightSibling = deleteNode(pNode->rightSibling->value);
        }
        return pNode;
    }
}

/* !!! Code to print AVL Tree taken from site: http://eduinf.waw.pl/inf/alg/001_search/0119.php#P4  */

void TreeAVL::printBT(string sp,string sn, NodeAVL * v) {
    string s;
    string cr = "  ";
    string cl = "  ";
    string cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    if (v)
    {
        s = sp;
        if (sn == cr)
            s[s.length() - 2] = ' ';
        if(v->rightSibling != NULL)
            printBT(s + cp, cr, v->rightSibling);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << v->value << ":" << v->bf << endl;

        s = sp;
        if (sn == cl)
            s[s.length() - 2] = ' ';
        if(v->leftSibling != NULL)
            printBT(s + cp, cl, v->leftSibling);
        }
}
