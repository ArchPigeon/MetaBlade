//Name: Pc.cpp
//Author: Cason White

#include "Pc.h"


Pc::Pc(Tile*t, char c) : Creature(t, c){
    
}

tuple <int, int> Pc::movePc(int d) {

    tuple <int, int> loc = this->getTile()->getLocation();
    int x = get <0> (loc);
    int y = get <1> (loc);

    switch(d) {
	
    case 1:
	this->moveCreature(x = x - 1, y = y -1);
	break;
	
    case 2:
	this->moveCreature(x, y = y - 1);
	break;

    case 3:
	this->moveCreature(x = x+1, y = y-1);
	break;

    case 4:
	this->moveCreature(x = x-1, y);
	break;

    case 5:
	break;

    case 6:
	this->moveCreature(x = x+1,y);
	break;

    case 7:
	this->moveCreature(x = x-1, y = y+1);
	break;

    case 8:
	this->moveCreature(x, y = y+1);
	break;

    case 9:
	this->moveCreature(x =  x+1, y = y+1);

    default:
	printf("incorrect direction");
    }

    return make_tuple (x,y);
}
