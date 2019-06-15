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
void Creature::setTile(Tile* from, Tile* to) {
    to->setCreature(this);
    from->setCreature(NULL);
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
    Tile* from = this->getTile();
    Tile* to = from->getParent().getTileAt(x, y);
if(to->getPassable() == true)
    {
	to->setCreature(this);
	this->setTile(from, to);
    }
}
