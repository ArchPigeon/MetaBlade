//Name:Serialize.h
//Author:Cason White

//Serialize is a namespace that utilizes the boost library to save other
//objects within the Metablade project.  The two functions, saveObj and
//loadObj, are used simply by specifying the object to be saved or loaded and
//a file name.  Serialize can be used on any object within the Metablade
//project, provided the boost::serialization framework is set up within the
//class.


#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

using namespace std;



namespace Serialize {
    template<class T>
    void saveObj(T & obj, const char* fileName){
    ofstream ofs(fileName);
    boost::archive::text_oarchive oa(ofs);
    oa << obj;
    ofs.close();
}
    
    template<class T>
    void loadObj(T & obj, const char* fileName){
    ifstream ifs(fileName);
    boost::archive::text_iarchive ia(ifs);
    ia >> obj;
    ifs.close();
}

    
}

#endif
