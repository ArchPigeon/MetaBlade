#include "Map.h"
#include "Creature.h"
#include "Pc.h"
#include "Tile.h"

#include <cstdio>

using namespace std;

//void eventLoop()
int main() {
    
    Map m(10, 10);
    char c = '0';

    m.createArena();
    m.printMap();

    printf("enter a numeric direction, or type q to quit: ");
    scanf( "%c",  &c);
    
     while(c != 'q') {
	 m.getPcLoc()->getCreature()->movePc(c - '0');
	 m.printMap();
	 printf("enter a numeric direction, or type q to quit: ");
	 scanf( "%c",  &c);
     }
    return 0;
}
