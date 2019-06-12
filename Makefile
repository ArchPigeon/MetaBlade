CXXFLAGS = -g -Wall  -Wuninitialized
OFILES = Tile.o Creature.o Pc.o  Map.o
CXX = g++

MetaBlade : $(OFILES)
	$(CXX)  $(CXXFLAGS) -o MetaBlade $(OFILES) main.cpp

Map.o: Map.cpp Map.h 
	$(CXX) $(CXXFLAGS) -c Map.cpp

Tile.o: Tile.cpp Tile.h 
	$(CXX) $(CXXFLAGS) -c Tile.cpp

Creature.o: Creature.cpp Creature.h 
	$(CXX) $(CXXFLAGS) -c Creature.cpp

Pc.o: Pc.cpp Pc.h
	$(CXX) $(CXXFLAGS) -c Pc.cpp

clean:
	rm $(OFILES) MetaBlade
