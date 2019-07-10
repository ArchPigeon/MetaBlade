// Name: Creature.cpp
// Author: Cason White


// Description:
// Creature.cpp is the class file which stores information on a particular creature,
// whether that be a monster or the pc.

// Creature.cpp contains the following methods
// Tile* getTile() - gets the current location of the creature
// void setTile() - sets the current location of the creature
// Creature(loc, sym) - constructor which sets the location to loc, and the character symbol to sym


#include "Creature.h"

Creature::Creature(Tile* loc, char sym) : location(loc), symbol(sym) {

    getTile()->setCreature(this);
    
}

//moves the pointer pointing to this creature from one tile to another
void Creature::setTile(Tile* to) {
    to->setCreature(this);
    location->setCreature(NULL);
    location = to;
}

Tile* Creature::getTile() {
    return location;
}

char Creature::getSymbol() const {
    return symbol;
}

// moveCreature(x, y) moves a Creature object within it's containing Map object.  (x,y)
// denotes the (x,y) position within the two dimensional array they are to be moved to
void Creature::moveCreature(int x, int y) {
    Tile* to = getTile()->getParent()->getTileAt(x, y);
    if(to->getPassable() == true)
	{
	    this->setTile(to);
	}
}

void  Creature::movePc(int d) {

    Tile* t = getTile();
    tuple <int, int> loc = t->getLocation();
    Map* m = t->getParent();
    int x = get <0> (loc);
    int y = get <1> (loc);

    switch(d) {

    case 0:
	m->saveGame("test.txt");
	break;
	
    case 1:
	this->moveCreature(x - 1,y +1);
	m->setPcLoc(getTile());
	break;
	
    case 2:
	this->moveCreature(x, y + 1);
	m->setPcLoc(getTile());
	break;

    case 3:
	this->moveCreature(x+1, y+1);
	m->setPcLoc(getTile());
	break;

    case 4:
	this->moveCreature(x-1, y);
	m->setPcLoc(getTile());
	break;

    case 5:
	break;

    case 6:
	this->moveCreature(x+1,y);
	m->setPcLoc(getTile());
	break;

    case 7:
	this->moveCreature(x-1, y-1);
	m->setPcLoc(getTile());
	break;

    case 8:
	this->moveCreature(x, y - 1);
	m->setPcLoc(getTile());
	break;

    case 9:
	this->moveCreature(x+1, y-1);
	m->setPcLoc(getTile());
	break;
    }

    //return make_tuple (x,y);
}
