#include <iostream>
#include <string>
#include <cstdlib>
#include<time.h>
#include "TreeAVL.hh"

using namespace std;

int main() {
    TreeAVL tree;
    

    /* !!! Code taken from site:http://eduinf.waw.pl/inf/alg/001_search/0119.php#P4 */
    // ustawiamy łańcuchy znakowe, ponieważ nie wszystkie edytory pozwalają
    // wstawiać znaki konsoli do tworzenia ramek.
    // cr = +--
    //      |

    // cl = |
    //      +--

    // cp = |
    //      |



    int Tk[32];   // tablica kluczy węzłów
    int i,x,i1,i2;

    srand(time(NULL));        // inicjujemy generator pseudolosowy


    for(i = 0; i < 32; i++)   // Tablicę wypełniamy wartościami kluczy
        Tk[i] = i + 1;

    for(i = 0; i < 300; i++)  // Mieszamy tablicę
    {
        i1 = rand() % 32;       // Losujemy 2 indeksy
        i2 = rand() % 32;

        x = Tk[i1];             // Wymieniamy Tk[i1] <--> Tk[i2]
        Tk[i1] = Tk[i2];
        Tk[i2] = x;
    }


    for(i = 0; i < 32; i++)   // Na podstawie tablicy tworzymy drzewo AVL
    {
        cout << Tk[i] << " ";
        tree.addNode(tree.rootNode,Tk[i]);
    }

    cout << endl << endl;

    tree.printBT("","",tree.rootNode); 


    


    /* !!! */


}
