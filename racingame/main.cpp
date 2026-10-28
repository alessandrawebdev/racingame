#include <iostream>
#include "intro.hpp"
#include "engine.hpp"

using namespace std;

int main() {
    header title = header(); //stampa del titolo di intro
    title.onTitle();
    int choice;
    engine game;
    do { //scegliere una delle tre gare
        choice = title.mode();
        game = engine(choice);
        game.start(); //avvio del gioco stesso (engine)
    } while (game.restart()); //fino a quando ricomincio
    return 0;

}



