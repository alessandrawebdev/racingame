#ifndef COINS_H
#define COINS_H
#include "obstacle.hpp"

//file header di coins.cpp che contiene le definizioni e prototipi dell'oggetto "bomb" 
//moneta

class coin : public obstacle {
private:
	char k; 
public:
	coin();
	coin(int x, int y, int broke, int coeff, char kToPrint);
	void drawOn(track& r); 
	bool okCancel();
	bool onClash(int x, int y);
	void draw(track& r, int y, int x, char onKPrint);
};
#endif
