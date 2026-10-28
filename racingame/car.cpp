#include "car.hpp"
#include <iostream>
using namespace std;

car::car() {}

car::car(int posx, int posy, char iconY) {
	posX = posx;
	posY = posy;
	isIcon = iconY; //"punto disegnato"
}

//ottengo le posizioni 
int car::getPosX() {
	return posX;
}
int car::getPosY() {
	return posY;
}

//gestiore le direzioni con i tasti da tastiera
//utilizzo enumerazione
void car::moveTo(enumW way) {
	switch (way) {
	case RIGHT:
		posX = posX + 4;
		break;
	case LEFT:
		posX = posX - 4;
		break;
	}
}

//disegna macchinina sulla strada
void car::onRoad(track &icon) {
	icon.map[posY][posX] = isIcon;
	icon.map[posY+1][posX] = isIcon;
	icon.map[posY+2][posX] = isIcon;
	icon.map[posY-1][posX] = isIcon;
	icon.map[posY][posX-1] = isIcon;
	icon.map[posY][posX+1] = isIcon;
	icon.map[posY+2][posX-1] = isIcon;
	icon.map[posY+2][posX+1] = isIcon;
}

void car::onIcon(char icon) {
	isIcon = icon; 
}
