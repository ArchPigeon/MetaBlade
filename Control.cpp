
/*
int Creature::movePc() {

    Tile* t = getTile();
    tuple <int, int> loc = t->getLocation();
    Map* m = t->getParent();
    int x = get <0> (loc);
    int y = get <1> (loc);

    int d = m->getMainInput();

    switch(d) {

    case (int)'0':
        //	m->saveGame("test.txt");
        break;

    case (int)'b':
    case (int)'1':
        this->moveCreature(x - 1,y +1);
        m->setPcLoc(getTile());
        break;

    case (int)'j':
    case (int)'2':
        this->moveCreature(x, y + 1);
        m->setPcLoc(getTile());
        break;

    case (int)'n':
    case (int)'3':
        this->moveCreature(x+1, y+1);
        m->setPcLoc(getTile());
        break;

    case (int)'h':
    case (int)'4':
        this->moveCreature(x-1, y);
        m->setPcLoc(getTile());
        break;

    case (int)'.':
    case (int)'5':
        //	m->loadGame("test.txt");
        break;

    case (int)'l':
    case (int)'6':
        this->moveCreature(x+1,y);
        m->setPcLoc(getTile());
        break;

    case (int)'y':
    case (int)'7':
        this->moveCreature(x-1, y-1);
        m->setPcLoc(getTile());
        break;

    case (int)'k':
    case (int)'8':
        this->moveCreature(x, y - 1);
        m->setPcLoc(getTile());
        break;

    case (int)'u':
    case (int)'9':
        this->moveCreature(x+1, y-1);
        m->setPcLoc(getTile());
        break;
    }
    return d;
    //return make_tuple (x,y);
}
*/