#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "track.hpp"

//file header di obstacle.cpp che contiene le definizioni e prototipi dell'oggetto "obstacle" 
//ostacolo

class obstacle {
protected:
	int xPos;
	int yPos;
	int broken;
	bool cancel; //eliminare dalla lista 
public:
	obstacle();
	obstacle(int x, int y, int broke, int coeff);
	int getX();
	int getY();
	void goCancel(bool canc); //per pulire (?) schermata
	int okBroke(); //per punteggio dopo lo scontro
	void moveTo();
};
#endif