#include "intro.hpp"
#include "track.hpp"
#include <iostream>
#include <stdbool.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

header::header() {}

void header::onTitle() {
	HANDLE hconsole;  //stampa titolo e intro
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE); //funzione per usare handle per scrivere e leggere nella console
	cout << "\n\n\n      *** RACINGAME *** \n\n"; //titolo
	cout << "      Press any kay to continue..\n"; //occorre premere un tasto per iniziare
	while (!_kbhit()) {}     //attende che venga premuto un tasto 
	int key = _getch(); //dichiaro una variabile per la funzione di lettura del carattere (facilitare codice)
}

int header::mode() {   //mostra il menù delle tre gare per scegliere una delle tre e poi iniziare
	system("CLS"); //"pulire" lo schermo
	ShowConsoleCursor(false); //nasconde il cursore dalla console
	HANDLE hconsole; //stampa le tre tipologie di gare
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int key;
	int onCase = 0; //sono posizionato sulla prima scelta
	bool ready = false; //booleano che è true quando viene fatta la scelta    

	gotoxy(5, 1); //stampa a video il menù delle gare possibili
	cout << "Choose your race: ";
	gotoxy(5, 5);
	SetConsoleTextAttribute(hconsole, 'x');
	cout << "RACE 1";
	SetConsoleTextAttribute(hconsole, 15);
	gotoxy(5, 7);
	cout << "RACE 2";
	gotoxy(5, 9);
	cout << "RACE 3";
	while (!ready) {
		if (_kbhit()) { //il giocatore schiaccia un tasto
			key = _getch();
			if (key == 80) { //muove freccia in giu
				onCase++;
				onCase %= 3;
			}
			else if (key == 72) { //muove freccia in su
				if (onCase != 0) 
					onCase--;
				else onCase = 2;
			}
			else if (key == 13) {
				ready = true; 
			}
			switch (onCase) //switch per la scelta della gara
			{
			case 0: //gara1
				gotoxy(5, 5);
				SetConsoleTextAttribute(hconsole, 'x');
				cout << "RACE 1";
				SetConsoleTextAttribute(hconsole, 15);
				gotoxy(5, 7);
				cout << "RACE 2";
				gotoxy(5, 9);
				cout << "RACE 3";
				break;
			case 1: //gara2
				gotoxy(5, 7); 
				SetConsoleTextAttribute(hconsole, 'x');
				cout << "RACE 2";
				gotoxy(5, 5);
				SetConsoleTextAttribute(hconsole, 15);
				cout << "RACE 1";
				gotoxy(5, 9);
				cout << "RACE 3";
				break;
			case 2: //gara3
				gotoxy(5, 9);
				SetConsoleTextAttribute(hconsole, 'x');
				cout << "RACE 3";
				gotoxy(5, 5);
				SetConsoleTextAttribute(hconsole, 15);
				cout << "RACE 1";
				gotoxy(5, 7);
				cout << "RACE 2";
				break;
			}
		}
	}
	return onCase;  //restituisce la gara scelta
}