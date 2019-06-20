// Name: Creature.h
// Author: Cason White


// Description:
// Creature.h is the header for a class which stores information on a particular creature,
// whether that be a monster or the pc.

// Creature.h contains the following members
// vector inv #TODO
// Tile* location - A pointer to the tile that the creature is currently in
// char symbol - the symbol that represents the creature
// tuple pLoc - the current (x,y) position of the creature

#ifndef CREATURE_H
#define CREATURE_H

#include "Map.h"
#include  "Tile.h"


class Tile;
class Map;
class Creature {

 private:
    
    Tile* location;
    char symbol;


 public:

    Creature(Tile* loc, char sym);
    
    void setTile(Tile* to);
    Tile* getTile();

    char getSymbol() const;

    void moveCreature(int x, int y);
    void movePc(int d);


};

#endif
