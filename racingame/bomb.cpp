#include "bomb.hpp"

bomb::bomb() {}

bomb::bomb(int x, int y, int broke, int coeff, char iconY) :obstacle(x, y, broke, coeff) {
	isIcon = iconY;
}

//posizionare la bomba sulla mappa
void bomb::drawOn(track& r) {
	if (yPos < r.getH() + 3 && !cancel) {
		draw(r, yPos, xPos);
	}
	else cancel = true;
}

//disegnare la bomba sulla mappa con relativi controlli 
void bomb::draw(track& r, int y, int x) {
	if (y >= 0 && y < r.getH())
		r.map[y][x] = isIcon;
}

bool bomb::okCancel() { 
	return cancel;
}

//controllo se il giocatore ha avuto uno scontro da basso, destra e sinistra
bool bomb::clash(int x, int y) {
	if (((x >= xPos - 1 && x <= xPos + 2) && (y >= yPos && y <= yPos + 1)) 
		|| ((x <= xPos + 2 && x >= xPos) && (y >= yPos - 4 && y <= yPos + 1)) 
		|| ((x <= xPos + 1 && x >= xPos - 1) && (y >= yPos - 4 && y <= yPos + 1)) 
		)
		return true;
	else return false;   
}