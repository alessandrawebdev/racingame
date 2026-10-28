#include "engine.hpp"
using namespace std;

engine::engine() {}

engine::engine(int isChoosen){
	choice = isChoosen; 
	maxOb = 6; //per "schermata" ci sono massimo 6 ostacoli 
	numbOb = 0;
	points = tot = level = 1; //inizia da livello 1 con punti 1
	road = track();
	player = car(road.getW() / 2, road.getH() - 3, '^'); //per disegnare la macchinina del giocatore
	isBurst = isCollect = false;
	gogo = 0;
	flashes = 0; //far comparire e scomparire (flash) la macchinina per dare l'idea di aver perso punti dopo aver avuto uno scontro
	quit = false;
	//teste delle liste
	headCoin = NULL;
	headBomb = NULL;
	headEnemy = NULL;	
}

//motore del gioco
void engine::start() {
	int key = 32; //tasto 
	player.onRoad(road);

	while (points>0) {
		gogo++;
		if(points>100)	level = points / 100; //100-199pt livello1, 200-299pt livello2, ecc
		//qui vado a gestire le varie difficoltà dei livelli
		//dopo un x livello aumento gli ostacoli per aumentare la difficoltà
		if (level > 5) {
			maxOb = 10;
		}
		else if (level >= 10) {
			maxOb = 13;
		}
		else if (level >= 15) {
			maxOb = 18;
		}
		setMap(); //risistema la mappa a seconda del numero di ostacoli
		//flash-macchinina dopo uno scontro con ostacolo
		if (flashes > 0) flashes--;
		if (flashes % 2 != 0) player.onIcon(' '); //disegna macchina giocatore
		else player.onIcon('^');
		//sistemo la "schermata" di gioco
		run();
		bombOn(headBomb);
		enemyOn(headEnemy);
		pointsOn(headCoin);
		//per individuare scontro con gli ostacoli
		onClashBomb(headBomb, player.getPosX(), player.getPosY(), &points, level, &flashes, isBurst);
		onClashEnemy(headEnemy, player.getPosX(), player.getPosY(), &points, level, &flashes, isBurst);
		onClashPoints(headCoin, player.getPosX(), player.getPosY(), &points, level, &flashes, isCollect);
        
		headBomb = goBomb(headBomb, numbOb); //elimino dalla lista bombe già esplose
		headEnemy = goEnemy(headEnemy, numbOb);// elimino dalla lista macchinine già scontrate
		headCoin = goCoin(headCoin, numbOb); //elimino dalla lista monete già raccolte

		road.okToNew(); //sistemo come nuova la schermata di gioco (aggiorno)
		player.onRoad(road); //ok per macchina giocatore
		inBomb(road, headBomb); //headBomb è la testa della lista che contiene le bombe
		inEnemy(road, headEnemy);
		inCoin(road, headCoin); //metto testa lista
		road.insert(isBurst);
        
		gotoxy(road.getW() + 1, 6); //conteggio punti
		cout << "Points: " << points << "   ";
		gotoxy(road.getW() + 1, 8); //conteggio livello
		cout << "Level: " << level << "   ";
	}
	//out of game -> game over (ma posso ricominciare da capo la partita)
	//pulisco e stampo
	system("cls");
	gotoxy(15, 12);
	cout << "GAME OVER!";
	gotoxy(15, 13);
	cout<<"Points: " << tot;
	Sleep(1000);
	gotoxy(10, 20);
}

void engine::run() {
	//funzione per gestire l'input da tastiera
	//prevede il movimento tramite frecce
	int key;
	if (_kbhit()) {
		key = _getch(); //"key logger"
		if (key == 75) {
			player.getPosX(); 
			player.moveTo(LEFT); 
		} else if (key == 77) {
			player.getPosX(); 
			player.moveTo(RIGHT); 
		}
	}
}

//setto la mappa di gioco
void engine::setMap() {
	int i = rand() % 4;
	int x;
	switch (i) {
		case 0: //controllo per verificare che posso "piazzare" una macchina nemica
			x = rand() % (road.getW() - 4) + 1;
			if (okEnemy(road, x) && numbOb < maxOb) {
				numbOb++;
				headEnemy = addEnemy(headEnemy, x, choice);
			}
			break;
		case 1:
			x = rand() % (road.getW() - 4) + 1;
			break;
		case 2: //controllo per verificare che posso "piazzare" una moneta per raccogliere punti
			x = rand() % (road.getW() - 4) + 1;
			if (okPoints(road, x) && numbOb < maxOb) {
				numbOb++;
				headCoin = addCoin(headCoin, x , choice);
			}
			break;
		case 3: //controllo per verificare che posso "piazzare" una bomba
			x = rand() % (road.getW() - 3) + 1;
			if (okBomb(road, x) && numbOb < maxOb) {
				numbOb++;
				headBomb = addBomb(headBomb, x, choice);
			}
			break;
		}
}

//ricominciare la partita
bool engine::restart() {
	system("cls");
	bool ready = false;
	int key;
	int scelta = 0;
	ShowConsoleCursor(false);
	HANDLE hconsole;
	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "\n\n    Press Enter to restart..";

	while (!ready) {
		if (_kbhit()) {
			key = _getch();
			if (key == 13) {
				ready = true;
			}
		}
	}
	return true;
}