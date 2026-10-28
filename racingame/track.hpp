#ifndef TRACK_H
#define TRACK_H
#include <iostream>
#include "basic.hpp"

//file header di track.cpp che contiene le definizioni e prototipi dell'oggetto "track" 
//strada

class track {
private:
	static const int hv = 30;
	static const int wv = 45;
	
public:
	char map[hv][wv];
	track();
	void insert(bool isBurst); 
	int getW();
	int getH();
	void okToNew();
};
#endif