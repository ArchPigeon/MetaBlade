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

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Tile;
class Map;
class Creature {

 private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
     	ar & location;
	ar & symbol;
    }
    
    Tile* location = NULL;
    char symbol = '?';


 public:

    Creature(Tile* loc, char sym);
    Creature() {}
    
    void setTile(Tile* to);
    Tile* getTile();

    char getSymbol() const;

    void moveCreature(int x, int y);
    int movePc();


};

#endif
