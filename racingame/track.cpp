#include "track.hpp"
using namespace std;

track::track() {
	for (int i = 0; i < hv; i++) {
		for (int j = 0; j < wv; j++) {
			map[i][j] = '.';
		}
	}
}

//funzione per pulire la strada prima di stampare nuovamente ostacoli e auto utente
void track::okToNew() {
	for (int i = 0; i < hv; i++) {
		for (int j = 0; j < wv; j++) {
			if (j == 0 || j == wv - 1)
				map[i][j]='I'; //bordi della strada
			else map[i][j] = '.';
		}
	}
}

//stampa a video della strada
void track::insert(bool isShield) {
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < hv; i++) {
		for (int j = 0; j < wv; j++) {
			gotoxy(j, i);
			//non sono presenti elementi in questo punto della strada
			if (map[i][j] == '.') {
				SetConsoleTextAttribute(hconsole, 15);
				cout << ' ';
			}
			else { 
				cout << map[i][j];
			}
		}
	}
}

//ottengo dimensioni per altezza e larghezza della matrice-mappa
int track::getW() {
	return wv;
}
int track::getH() { 
	return hv; 
}

