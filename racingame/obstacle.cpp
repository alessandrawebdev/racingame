#include "obstacle.hpp"

obstacle::obstacle() {}

obstacle::obstacle(int x, int y, int broke, int coeff) {
	xPos = x;
	yPos = y;
	cancel = false;
	broken = broke;
	
}

int obstacle::okBroke() {
	return broken;
}

int obstacle::getX() { 
	return xPos; 
}

int obstacle::getY() { 
	return yPos; 
}

void obstacle::goCancel(bool canc) {
	cancel = canc;
}

void obstacle::moveTo() {  //scorrere ostacolo nella mappa
	yPos++;
}
