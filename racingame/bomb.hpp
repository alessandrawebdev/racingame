#ifndef BOMB_H
#define BOMB_H
#include "obstacle.hpp"

//file header di bomb.cpp che contiene le definizioni e prototipi dell'oggetto "bomb" 
//bomba

class bomb : public obstacle {
private:
	char isIcon;
public:
	bomb();
	bomb(int x, int y, int broke, int coeff, char iconY);
	void drawOn(track& icon); 
	void draw(track& icon, int y, int x);
	bool okCancel();
	bool clash(int x, int y); 
};
#endif
