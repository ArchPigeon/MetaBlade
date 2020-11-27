CXXFLAGS = -g -Wall  -Wuninitialized -lboost_serialization -lncurses
OFILES = Tile.o Creature.o Map.o Serialize.o
CXX = g++

MetaBlade : $(OFILES)
	$(CXX)  $(CXXFLAGS) -o MetaBlade $(OFILES) main.cpp

Map.o: Map.cpp Map.h 
	$(CXX) $(CXXFLAGS) -c Map.cpp

Tile.o: Tile.cpp Tile.h 
	$(CXX) $(CXXFLAGS) -c Tile.cpp

Creature.o: Creature.cpp Creature.h 
	$(CXX) $(CXXFLAGS) -c Creature.cpp

#Pc.o: Pc.cpp Pc.h
#	$(CXX) $(CXXFLAGS) -c Pc.cpp

Serialize.o: Serialize.h
	$(CXX) $(CXXFLAGS) -c Serialize.h

clean:
	rm MetaBlade

cleanall:
	rm $(OFILES) MetaBlade
