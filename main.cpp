#include "Map.h"
#include "Creature.h"
#include "Pc.h"
#include "Tile.h"

#include <iostream>

//void eventLoop()
int main() {
    //   int x = 0;
    Map m(10, 10);

    m.createArena();
    m.printMap();
    return 0;
}
