#include "coins.hpp"

coin::coin() {}

coin::coin(int x, int y, int broke, int coeff, char kToPrint) : obstacle(x, y, broke, coeff) {
	k = kToPrint;
}

//disegnare la moneta sulla mappa
void coin::drawOn(track& r) {
	if (yPos < r.getH() + 1 && !cancel) {
		draw(r, yPos, xPos, k);
	}
	else cancel = true;
}

//stampa la moneta sulla mappa
void coin::draw(track& r, int y, int x, char onKPrint) {
	if (y >= 0 && y < r.getH()) {
		r.map[y][x] = onKPrint;
	}
}

//cancella la moneta 
bool coin::okCancel() {
	return cancel; 
}

//controllo il collezionamento delle monete da ogni lato
bool coin::onClash(int x, int y) {
	if (((x >= xPos - 1 && x <= xPos + 3) && (y >= yPos && y <= yPos + 1)) 
		|| ((x <= xPos + 3 && x >= xPos) && (y >= yPos - 2 && y <= yPos + 1)) 
		|| ((x <= xPos + 2 && x >= xPos - 1) && (y >= yPos - 2 && y <= yPos + 1)) 
		|| ((x >= xPos - 1 && x <= xPos + 3) && (y >= yPos - 2 && y <= yPos - 1)) 
		)
		return true; 
	else return false;  //nessuno scontro
}