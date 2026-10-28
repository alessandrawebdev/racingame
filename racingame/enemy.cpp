#include "enemy.hpp"

enemy::enemy() {}

enemy::enemy(int x, int y, int broke, int coeff, char iconY) :obstacle(x, y, broke, coeff) {
    isIcon = icon;
}

//posiziona
void enemy::drawOn(track& icon) {
    if (yPos < icon.getH() + 4 && !cancel) {
        draw(icon, yPos, xPos + 1);
        draw(icon, yPos - 1, xPos + 1);
        draw(icon, yPos - 1, xPos);
        draw(icon, yPos - 1, xPos + 2);
        draw(icon, yPos - 2, xPos + 1);
        draw(icon, yPos - 3, xPos + 1);
        draw(icon, yPos - 3, xPos);
        draw(icon, yPos - 3, xPos + 2);
    }
    else cancel = true;
}

//stampa sulla console dopo il controllo
void enemy::draw(track& icon, int y, int x) {
    if (y >= 0 && y < icon.getH())
        icon.map[y][x] = isIcon;
}

//cancella la macchina nemica
bool enemy::okCancel() { 
    return cancel; 
}

//controllo gli scontri da basso, destra e sinistra
bool enemy::clash(int x, int y) {
    if (((x >= xPos - 1 && x <= xPos + 3) && (y >= yPos && y <= yPos + 1)) 
        || ((x <= xPos + 3 && x >= xPos) && (y >= yPos - 5 && y <= yPos + 1)) 
        || ((x <= xPos + 2 && x >= xPos - 1) && (y >= yPos - 5 && y <= yPos + 1)) 
        )
        return true; // restituisce true con uno scontro avvenuto
    else return false;  //restituisce false con nessuno scontro
}