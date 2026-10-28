#ifndef ENEMY_H
#define ENEMY_H
#include "obstacle.hpp"

//file header di enemy.cpp che contiene le definizioni e prototipi dell'oggetto "enemy"
//macchina nemica

class enemy : public obstacle {
private:
	char isIcon, icon;
public:
	enemy();
	enemy(int x, int y, int broke, int coeff, char iconY);
	void drawOn(track& icon); 
	void draw(track& icon, int y, int x);
	bool okCancel();
	bool clash(int x, int y);
};
#endif