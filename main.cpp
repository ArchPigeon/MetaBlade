#include "Map.h"
#include "Creature.h"
#include "Pc.h"
#include "Tile.h"
#include "Serialize.h"

#include <cstdio>
#include <iostream>


using namespace std;

//void eventLoop()
int main() {
    
    Map m(10, 10);
    //    char c = '0';

    m.createArena();
    m.printMap();
    Serialize::saveObj(m,"test");

    Map n;
    Serialize::loadObj(n,"test");
    n.printMap();
    
    // printf("enter a numeric direction or type q to quit: ");
    // scanf( "%c",  &c);
    
    //  while(c != 'q') {
    // 	 m.getPcLoc()->getCreature()->movePc(c - '0');
    // 	 m.printMap();
    // 	  printf("enter a numeric direction or type q to quit: ");
    // 	 scanf( "%c",  &c);
    //  }
    return 0;
}
