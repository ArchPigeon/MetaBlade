#include "Map.h"
#include "Creature.h"
#include "Pc.h"
#include "Tile.h"

#include <cstdio>
#include <fstream>


using namespace std;

//void eventLoop()
int main() {
    
    Map m(10, 10);
    char c = '0';

    m.createArena();
    m.printMap();

    m.saveGame("test.txt");

    Map n;

    std::ifstream ifs("test.txt");
    boost::archive::text_iarchive ia(ifs);
    ia >> n;

    n.printMap();

    
    
    // printf("enter a numeric direction, or type q to quit: ");
    // scanf( "%c",  &c);
    
    //  while(c != 'q') {
    // 	 m.getPcLoc()->getCreature()->movePc(c - '0');
    // 	 m.printMap();
    // 	 printf("enter a numeric direction, or type q to quit: ");
    // 	 scanf( "%c",  &c);
    //  }
     return 0;
}
