#include "TreeAVL.hh"

using namespace std;


int TreeAVL::treeHeight(NodeAVL *p)
{
    //if null there is no tree
    
    if (p == NULL)
    {
        return -1;
    }
    int left = treeHeight(p->leftSibling);      // Determine which subtree is higher
    int right = treeHeight(p->rightSibling);
    if(left > right)                            // Return the higher one
        return left + 1;                        // Plus one because of rootNode
    else if (right > left)
        return right + 1;
    return left + 1;                            // If subtrees are equal return left
}

void TreeAVL::setBf(NodeAVL *p)
{   
    // bf is set depending on subtrees height
    p->bf = treeHeight(p->rightSibling) - treeHeight(p->leftSibling);
}

NodeAVL *TreeAVL::rotateLL(NodeAVL *p)
{
    
    NodeAVL* temp;                              // Helper variable
	temp = p->rightSibling;                     // Put tmp in place of p right child
    temp->parent = p->parent;                   // Temp's parent is now p's parent
	p->rightSibling = temp->leftSibling;        // P right child become temp left child
    if (p->rightSibling != NULL) {              // If p has right child
        p->rightSibling->parent = p;            // Then it's parent becomes p
    }
	temp->leftSibling = p;                      // P becomes temp left child
	p->parent = temp;                           // Temp become p's parent

    if (temp->parent != NULL) {                 // If temp has parent
        if (temp->parent->rightSibling == p) {  // If right child of temp's parent is p
            temp->parent->rightSibling = temp;  // Right child of temp's parent becomes temp
        }
        else {                          
            temp->parent->leftSibling = temp;   // If not, left child of temp's parent becomes temp
            }
    }
    
	
    setBf(p);                                   // Setting balance factor of balanced nodes
    setBf(temp);
    return temp;                                
}

NodeAVL *TreeAVL::rotateRR(NodeAVL *p)
{
    
    NodeAVL* temp;                              // Helper variable
	temp = p->leftSibling;                      // Temp becomes p left child
    temp->parent = p->parent;                   // P's parent becomes temp's parent
	p->leftSibling = temp->rightSibling;        // P's left child becomes temp's right child
    if(p->leftSibling != NULL) {                // P's left child exists
        p->leftSibling->parent = p;             // P's left child's parent become p
    }   
	temp->rightSibling = p;                     // P becomes temp's right child
	p->parent = temp;                           // Temp becomes p's parent
    if(temp->parent != NULL){                   // If temp has parent
        if(temp->parent->rightSibling == p) {   // If p is temp's parent's right child
            temp->parent->rightSibling = temp;  // Temp becomes temp's parent's right child
        }
        else {
            temp->parent->leftSibling = temp;   // Else temp becomes temp's parent's left child
        }
    }

    setBf(temp);                                // Setting balance factor of balanced nodes
    setBf(p);
    return temp;
}

NodeAVL *TreeAVL::rotateLR(NodeAVL *p)
{
    p->leftSibling = rotateLL(p->leftSibling);  // Firstly rebalance left p's left child
    return rotateRR(p);                         // Then rebalance right p
}

NodeAVL *TreeAVL::rotateRL(NodeAVL *p)
{
    p->rightSibling = rotateRR(p->rightSibling); // Firstly rebalance right p's right child
    return rotateLL(p);                          // Then rotate left p
}

void TreeAVL::restoreBalanceFromRoot(NodeAVL *p)
{
    setBf(p);                                    // Set p's balance factor
    if (p->bf == -2)                             // If left subtree is higher
    {
        // If p's left child's left child subtree is higher rotate right if not rotate left then right
        if (treeHeight(p->leftSibling->leftSibling) >= treeHeight(p->leftSibling->rightSibling))
            p = rotateRR(p);
        else
            p = rotateLR(p);
    }
    else if (p->bf == 2) {                        // If right subtree is higher
        // If p's right child's right child subtree is higher rotate left if not rotate right then left
        if (treeHeight(p->rightSibling->rightSibling) >= treeHeight(p->rightSibling->leftSibling))
            p = rotateLL(p);
        else
            p = rotateRL(p);
    }
    if(p->leftSibling != NULL){                    // If p's left child exists rebalance it
        restoreBalanceFromRoot(p->leftSibling);
    }
    else if (p->rightSibling != NULL){             // If p's right child exists rebalance it
        restoreBalanceFromRoot(p->rightSibling);
    }
}

void TreeAVL::restoreBalanceFromLeaf(NodeAVL *p)
{
    setBf(p);                                    // Set p's balance factor
    if (p->bf == -2)                             // If left subtree is higher
    {
        // If p's left child's left child subtree is higher rotate right if not rotate left then right
        if (treeHeight(p->leftSibling->leftSibling) >= treeHeight(p->leftSibling->rightSibling))
            p = rotateRR(p);
        else
            p = rotateLR(p);
    }
    else if (p->bf == 2) {                        // If right subtree is higher
        // If p's right child's right child subtree is higher rotate left if not rotate right then left
        if (treeHeight(p->rightSibling->rightSibling) >= treeHeight(p->rightSibling->leftSibling))
            p = rotateLL(p);
        else
            p = rotateRL(p);
    }
    if (p->parent != NULL) {                       // If exists rebalance tree until reach root
        restoreBalanceFromLeaf(p->parent);
    }
    else {
        rootNode = p;
    }
}

void TreeAVL::printNode(NodeAVL *p)
{
    if (p == NULL)
    {
        std::cout << "Tree is empty!" << std::endl;
    }
    else
    {
        std::cout << p->value << "  ";
    }
}

void TreeAVL::addNode(NodeAVL *parent, float value)
{
    bool shouldGoLeft, shouldGo = true;             // Helper variable
    if (rootNode == NULL) {                         // If tree is empty
        rootNode = new NodeAVL(NULL, value);        // Create rootNode
    }
    else {
        NodeAVL                                     // Helper nodes
            *p = rootNode,
            *parent;
 
        while (shouldGo) {                          // While shouldGo is true
            if (p->value == value)                  // If given value exists end loop
                shouldGo = false;
 
            parent = p;                             // Parent becomes p which means go one level down in tree
 
            if(p->value > value){                   // If p's value is higher than value 
                p = p->leftSibling;                 // P becomes p's left child (go one level down)
                shouldGoLeft = true;                
            } else {
                p = p->rightSibling;                // Else p becomes p's right child
                shouldGoLeft = false;
            }
 
            if (p == NULL) {                        // If p is NULL it means that we found a place to insert node
                if (shouldGoLeft == true) {         // Determine if we should insert node on the left or right side
                    parent->leftSibling = new NodeAVL(parent, value);
                }
                else {
                    parent->rightSibling = new NodeAVL(parent, value);
                }
                shouldGo = false;                    //After node is added end loop
            }
        }
    }
}

void TreeAVL::addAndRebalance(NodeAVL *parent, float value)
{
    bool shouldGoLeft, shouldGo = true;             // Helper variable
    if (rootNode == NULL) {                         // If tree is empty
        rootNode = new NodeAVL(NULL, value);        // Create rootNode
    }
    else {
        NodeAVL                                     // Helper nodes
            *p = rootNode,
            *parent;
 
        while (shouldGo) {                          // While shouldGo is true
            if (p->value == value)                  // If given value exists end loop
                shouldGo = false;
 
            parent = p;                             // Parent becomes p which means go one level down in tree
 
            if(p->value > value){                   // If p's value is higher than value 
                p = p->leftSibling;                 // P becomes p's left child (go one level down)
                shouldGoLeft = true;                
            } else {
                p = p->rightSibling;                // Else p becomes p's right child
                shouldGoLeft = false;
            }
 
            if (p == NULL) {                        // If p is NULL it means that we found a place to insert node
                if (shouldGoLeft == true) {         // Determine if we should insert node on the left or right side
                    parent->leftSibling = new NodeAVL(parent, value);
                }
                else {
                    parent->rightSibling = new NodeAVL(parent, value);
                }
                restoreBalanceFromLeaf(parent);
                shouldGo = false;                    //After node is added end loop
            }
        }
    }
}

void TreeAVL::deleteNode(float value)
{

     if (rootNode != NULL){                         // If tree exists
 
        NodeAVL
            *p       = rootNode,                    // Helper nodes
            *parent  = rootNode,
            *deleteNode = NULL,
            *child   = rootNode;
    
        while (child != NULL) {                     // Search node to be deleted as long as child is NULL
            parent = p;                             // Go one level down
            p = child;
            if(value >= p->value){                  // If value to be deleted is greater than value of p
                child = p->rightSibling;            // Go right
            } else {
                child = p->leftSibling;             // Else go left
            }
            if (value == p->value)                  // If we find our value in tree
                deleteNode = p;                     // Found node is node to be deleted
        }
    
        if (deleteNode != NULL) {                   // If deleteNode is found
            deleteNode->value = p->value;           // Set deleteNode value as p's value

            if(p->leftSibling != NULL) {            // If p has left child 
                child = p->leftSibling;             // Child becomes p's left child
            } else {
                child = p->rightSibling;            // Else child becomes p's right child
            }    
            if (rootNode->value == value) {         // If value to delete is rootNode value 
                rootNode = child;                   // Child become new root
            }
            else {                                  // Else p doesn't have left child
                if (parent->leftSibling == p) {     // If parent's left child is p
                    parent->leftSibling = child;    // Parent's left child becomes child
                }
                else {
                    parent->rightSibling = child;   // Else parent's right child becomes child
                }
            }
            restoreBalanceFromLeaf(parent);
        }
    }
}

void TreeAVL::inorderTravel(NodeAVL *rootNode) {
    if(rootNode == NULL){                             // Tree doesn't exists
        return ;
    }
    inorderTravel(rootNode->leftSibling);             // First display left subtree then root
    printNode(rootNode);                             // And right subtree
    inorderTravel(rootNode->rightSibling);            
}

void TreeAVL::preorderTravel(NodeAVL *rootNode) {
    if(rootNode == NULL){                             // Tree doesn't exists
        return ;
    }
    printNode(rootNode);                              // Display root then left subtree
    preorderTravel (rootNode->leftSibling);           // And right subtree
    preorderTravel (rootNode->rightSibling);
}

void TreeAVL::postorderTravel(NodeAVL *rootNode) {
    if(rootNode == NULL){                             // Tree doesn't exists
        return ;
    }
    postorderTravel(rootNode->leftSibling);           // Display left subtree then right and root
    postorderTravel(rootNode->rightSibling);
    printNode(rootNode);
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
        printBT(s + cp, cr, v->rightSibling);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << v->value << ":" << v->bf << endl;

        s = sp;
        if (sn == cl)
            s[s.length() - 2] = ' ';
        printBT(s + cp, cl, v->leftSibling);
        }
}
