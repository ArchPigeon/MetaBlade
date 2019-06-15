//Name: Map.cpp
//Author: Cason White

//Map.cpp contains the member functions for the game map.  It contains the following:

//Map::Map(int x, int y) - constructor containing the x,y size of the map, creates a two dimensional
//array floor of Tile objects with x length and y height, as well as storing x and y ints .

//Tile* Map::getTileat(int x, int y) - returns a pointer to a Tile object within the two dimensional
// array floor

//void Map::createArena() - creates a test arena for the user to play around in

//cRow(row, r1, r2, value) - changes a row in the map from r1 to row size - r2 to value
//same for cColumn, only it changes columns.

#include "Map.h"

//the constructor creates a two dimensional vector of Tile pointers to act as the map.
//each tile by default is a floor.
Map::Map(int x, int y) {

    this->x = x;
    this->y = y;
     
    floor.resize(x);
    
    for(int i =0; i < this->x; i++) {
	
	floor[i].resize(y);
	for(int j = 0; j < this->y; j++) {
	    floor[i][j] = new Tile(*this);
	}
	//	Valloc(this->floor[i]);
	
    }
}

//allocates a column of Tile objects into memory
// void Map::Valloc(vector<Tile*> t) {
//     for(int i = 0; i < this->y; i++) {
// 	t[i] = new Tile(*this);
//     }
// }

tuple <int, int> Map::getSize(){
    return make_tuple(this->x, this->y);
}

Tile* Map::getTileAt(int x, int y) {
    return this->floor[x][y];
}


void Map::cRow(int row, int r1, int r2, TileType tile, bool value) {
    
    for(int j = r1; j < this->y - r2; j++) {
	Tile* t = this->floor[row][j];
	t->setLocation(row, j);
	t->setTileType(tile);
	t->setPassable(value);
    }
}

//TODO: add some default parameters so you can change either the tile or the value if you want
void Map::cColumn(int col, int r1, int r2, TileType tile, bool value) {
    for(int i = r1; i < this->x - r2; i++) {
	Tile* t =
	    this->floor[i][col];
	t->setLocation(i, col);
	t->setTileType(tile);
	t->setPassable(value);
    }
}

void Map::createArena() {
    //ya gotta add in the location for each tile
    //also add in the TileType
    int x = this->x;
    int y = this->y;

    this->cRow(0, 1, 1, wall, false);
    this->cRow(y-1, 1, 1, wall, false);
    this->cColumn(0, 0, 0, wall, false);
    this->cColumn(x-1, 0, 0, wall, false);
    
    
}

void Map::printMap() {
    for(int i = 0; i < x; i++) {
	for(int j = 0; j < y; j++) {
	    
	    Tile* t = floor[i][j];
	    if(t->getCreature() == NULL) {
		
		if(t->getTileType() == wall )
		       printf("#");
		else
		       printf(".");
	    }
	    else
		printf("@");
	}
	printf("\n");
    }
}

Map::~Map() {
    for(int i = 0; i<this->x; i++) {
	
	for(int j = 0; j<this->y; j++) {
	    
	    delete this->floor[i][j];
	}
	
    }
    
}
