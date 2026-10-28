#include "basic.hpp"
#include <Windows.h>

//muovere il cursore sul terminale
void gotoxy(int x, int y) {
	COORD coord; //dichiarazione delle coordinate di tipo COORD
	coord.X = x; //dichiarazione della coordinata x per le colonne
	coord.Y = y;//dichiarazione della coordinata y per le righe
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //ottenere handle per il buffer dello schermo della console
}
//funzione base per gestire il cursore
void ShowConsoleCursor(bool Show){
	int Size = 25;
	_CONSOLE_CURSOR_INFO CurInfo;
	if (Size <= 0)
		Size = 1;
	if (Size > 100)
		Size = 100;
	CurInfo.dwSize = Size;
	CurInfo.bVisible = Show;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo); //"richiamo" della funzione SetConsoleCursorInfo()
}