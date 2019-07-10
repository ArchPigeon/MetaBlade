// Name: Tile.h
// Author: Cason White


// Description:
// Tile.h is the header for a class which stores information on individual tiles on a map.
// Tile.h contains the following members:

// Private:
// bool tileType - an indicator for whether the tile is a floor or wall.  True for floor, false for wall.
// TileKind material - the type of material the floor or wall is made out of.  Currently only dirt exists.
// TODO: create a paging object to store items
// Creature* inhab - a pointer to the creature that is currently inhabiting the tile.


#ifndef TILE_H
#define TILE_H

#include <tuple>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "TileTypes.h"
#include "Creature.h"
#include "Map.h"

using namespace std;


class Map;
class Creature;
class Tile {
    
private:
     friend class boost::serialization::access;
     template<class Archive>
     void serialize(Archive & ar, const unsigned int version) {
     	ar & parent;
     	ar & passable;
     	ar & tile;
     	ar & material;
     	ar & inhab;
     	ar & xloc;
     	ar & yloc;
     }
    Map* parent = NULL;
    bool passable = true;
    TileType tile = floor;
    TileKind material = dirt;
    Creature* inhab = NULL;
    int xloc = 0;
    int yloc = 0;


public:
    
    Tile(Map* p, int x, int y);
    Tile() {}

    Map* getParent();
    
    void setPassable(bool t);
    bool getPassable() const;

    void setTileType(TileType t);
    TileType getTileType();
    
    void setCreature(Creature* inh);
    Creature* getCreature() const;

    void setTileMaterial(TileKind t);
    TileKind getTileMaterial() const;

    void setLocation(int x, int y);
    tuple <int, int> getLocation() const;


};

#endif
