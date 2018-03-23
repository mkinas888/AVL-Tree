#include <iostream>
#include <string>
#include <cstdlib>
#include<time.h>
#include <chrono>
#include "TreeAVL.hh"

using namespace std;
using namespace std::chrono;


int main() {
    TreeAVL tree;
    

    /* !!! Code of printing tree was taken from site:http://eduinf.waw.pl/inf/alg/001_search/0119.php#P4 */
    // ustawiamy łańcuchy znakowe, ponieważ nie wszystkie edytory pozwalają
    // wstawiać znaki konsoli do tworzenia ramek.
    // cr = +--
    //      |

    // cl = |
    //      +--

    // cp = |
    //      |



    float Tk[100000];   // tablica kluczy węzłów
    int i,x,i1,i2;

    srand(time(NULL));        // inicjujemy generator pseudolosowy


    for(i = 0; i < 100000; i++)   // Tablicę wypełniamy wartościami kluczy
        Tk[i] = i + 1;
    
    for(i = 0; i < 200000; i++)  // Mieszamy tablicę
    {
        i1 = rand() % 100000;       // Losujemy 2 indeksy
        i2 = rand() % 100000;

        x = Tk[i1];             // Wymieniamy Tk[i1] <--> Tk[i2]
        Tk[i1] = Tk[i2];
        Tk[i2] = x;
    }
        /* !!! */



    high_resolution_clock::time_point t1 = high_resolution_clock::now();    // Get time before function


    for(i = 0; i < 100000; i++)                                               // Create AVL tree from array
    {
        tree.addNode(tree.rootNode,Tk[i]);
    }
    tree.restoreBalance(tree.rootNode);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();    // Get time after function
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();         // Time needed to add all nodes
    cout << duration;




    cout << endl << endl;
    tree.setBf(tree.rootNode);
    tree.printBT("","",tree.rootNode);                                  // Print tree
    cout << tree.rootNode->bf << endl;
    cout << tree.treeHeight(tree.rootNode) << endl;

    high_resolution_clock::time_point t3 = high_resolution_clock::now();

    for(i = 0; i < 99999; i++)                                            // Remove all node except of the last one
    {
        tree.deleteNode(Tk[i]);
    }

    tree.restoreBalance(tree.rootNode);                                

    high_resolution_clock::time_point t4 = high_resolution_clock::now();     
    auto duration1 = duration_cast<microseconds>( t4 - t3 ).count();    // Time needed to delete nodes
    cout << duration1;
    
    cout << tree.rootNode->value << endl << endl << endl;
    tree.printBT("","",tree.rootNode); 

}
