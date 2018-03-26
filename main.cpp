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



    float Tk[100];   // tablica kluczy węzłów
    int i,x,i1,i2;

    srand(time(NULL));        // inicjujemy generator pseudolosowy


    for(i = 0; i < 100; i++)   // Tablicę wypełniamy wartościami kluczy
        Tk[i] = i + 1;
    
    for(i = 0; i < 200; i++)  // Mieszamy tablicę
    {
        i1 = rand() % 100;       // Losujemy 2 indeksy
        i2 = rand() % 100;

        x = Tk[i1];             // Wymieniamy Tk[i1] <--> Tk[i2]
        Tk[i1] = Tk[i2];
        Tk[i2] = x;
    }
        /* !!! */



    high_resolution_clock::time_point t1 = high_resolution_clock::now();    // Get time before function


    for(i = 0; i < 100; i++)                                               // Create AVL tree from array
    {
        tree.addAndRebalance(tree.rootNode,Tk[i]);
    }
    //tree.restoreBalanceFromRoot(tree.rootNode);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();    // Get time after function
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();         // Time needed to add all nodes




    cout << endl << endl;
    tree.printBT("","",tree.rootNode);    // Print tree
    cout << duration << endl;
    
    cout << endl << endl;          
    tree.inorderTravel(tree.rootNode);
    cout << endl << endl;
    tree.preorderTravel(tree.rootNode);
    cout << endl << endl;
    tree.postorderTravel(tree.rootNode);
    cout << endl << endl <<  duration;

    
}
