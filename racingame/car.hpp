#ifndef CAR_H
#define CAR_H
#include "track.hpp"

//file header di car.cpp che contiene le definizioni e prototipi dell'oggetto "car" 
//macchina del giocatore

using namespace std;

enum enumW { //enumerazione per le due direzioni
    RIGHT = 0,
    LEFT = 1 
};

class car {
protected:
    int posX;
    int posY;
    char isIcon;
public:
    car();
    car(int posx, int posy, char iconY);
    int getPosX();
    int getPosY();
    void moveTo(enumW way);
    void onRoad(track &icon);
    void onIcon(char icon);
};
#endif