#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: treeAVL
	./treeAVL

treeAVL: obj obj/main.o obj/TreeAVL.o
	g++ -Wall -pedantic -std=c++0x -o treeAVL obj/main.o obj/TreeAVL.o

obj:
	mkdir obj

obj/TreeAVL.o: TreeAVL.cpp
	g++ -c ${CXXFLAGS} -o obj/TreeAVL.o TreeAVL.cpp

obj/main.o: main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o main.cpp

clean:
	rm -f obj/*.o treeAVL
