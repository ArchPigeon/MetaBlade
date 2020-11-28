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

    m.createArena();
    // Serialize::saveObj(m,"test");

    // Map n;
    // Serialize::loadObj(n,"test");
    // n.printMap();
    
    // printf("enter a numeric direction or type q to quit: ");
    // scanf( "%c",  &c);
    int c;

    do{
      m.printMap();
      c =  m.getPcLoc()->getCreature()->movePc();
      m.refreshMain();
    } while((char)c != (int)'q');
    m.getMainInput();
    return 0;
}
