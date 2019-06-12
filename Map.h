// Name: Map.h
// Author: Cason White

//Map.h is the header for a class that stores tile info and map-based functions, including
//methods that create a debug arena map for testing purposes.

//The members are as follows:
//Tile* floor - a 2d array which stores the information of every tile on the floor, as well as it's location,
//                      denoted by the (x, y) position of the array.



#ifndef MAP_H
#define MAP_H

#include "Creature.h"
#include "Tile.h"

#include <tuple>
#include <vector>

using namespace std;

class Tile;
class Creature;
class Map {

private:
    vector <vector <Tile*> > floor;
    int x;
    int y;

    void VTalloc(vector<Tile*> t);

public:

    tuple<int, int> getSize();
    
    Tile* getTileAt(int x, int y);

    void cRow(int row, int r1, int r2, TileType tile, bool value);
    void cColumn(int col, int r1, int r2, TileType tile, bool value);
    
    void createArena();
    void pMovePlayer(char dir);

    void printMap();
    // Creature& getPlayer() const;
    // void setPlayer(Tile* loc);

    
    
    
    Map(int x, int y);
    ~Map();


};
#endif
