#include "lists.hpp"

//bomb e coin un solo punto, menemy 8 come car



//controlla se è possibile inserire un oggetto nella mappa
bool okBomb(track r, int x) {
	if (r.map[0][x] == '.') // && r.map[0][x + 1] == '?') 
		return true;
	else 
	return false;
}

//funzione per aggiungere un elemento alla lista 
bombs* addBomb(bombs* head, int x, int isChoosen) {
	if (head == NULL) {
		head = new bombs;
		head->c = bomb(x, -1, (isChoosen + 1) * 1, (isChoosen + 1) * 1, '+'); 
		head->next = NULL;
		return head;
	}
	else {
		head->next = addBomb(head->next, x, isChoosen);
		return head;
	}
}

//scorre la lista e chiama per ogni elemento il metodo moveTo
void bombOn(bombs* head) {
	bombs* tmp = head;
	while (tmp != NULL) {
		tmp->c.moveTo();
		tmp = tmp->next;
	}
}

//scorre la lista e stampa nella matrice della strada l'elemento
void inBomb(track& r, bombs* head) {
	bombs* tmp = head;
	while (tmp != NULL) {
		tmp->c.drawOn(r);
		tmp = tmp->next;
	}
}

//scorre la lista e controlla quali elementi sono da eliminare perchè hanno avuto uno scontro
bombs* goBomb(bombs* head, int& n) {
	if (head == NULL)	return NULL;
	else {
		if (head->c.okCancel()) {
			n = n - 1;
			return goBomb(head->next, n);
		}
		else {
			head->next = goBomb(head->next, n);
			return head;
		}
	}
}

//scorre la lista intera e controlla se ci sono stati scontri
void onClashBomb(bombs* head, int x, int y, int* score, int step, int* flashes, bool burst) {
	bombs* tmp = head;
	while (tmp != NULL) {
		if (tmp->c.clash(x, y)) {
			tmp->c.goCancel(true);
				*score -= tmp->c.okBroke();
				*flashes = 5; //flash della macchinina del giocatore durante gli scontri
		}
		tmp = tmp->next;
	}
}

//controlla se è possibile inserire un oggetto 
bool okEnemy(track r, int x) {
	if (r.map[0][x] == '.' && r.map[0][x + 1] == '.' && r.map[0][x + 2] == '.') 
		return true;
	else 
		return false;
}

//aggiungere un elemento macchina nemica alla lista
enemies* addEnemy(enemies* head, int x, int isChoosen) {
	if (head == NULL) {
		head = new enemies;
		head->e = enemy(x, -1, (isChoosen + 1) * 2, (isChoosen + 1) * 1, '8'); 
		head->next = NULL;
		return head;
	}
	else {
		head->next = addEnemy(head->next, x, isChoosen);
		return head;
	}
}

//scorre la lista e chiama per ogni elemento il metodo moveTo 
void enemyOn(enemies* head) {
	enemies* tmp = head;
	while (tmp != NULL) {
		tmp->e.moveTo();
		tmp = tmp->next;
	}
}

//scorre la lista e stampa nella matrice della strada l'elemento
void inEnemy(track& r, enemies* head) {
	enemies* tmp = head;
	while (tmp != NULL) {
		tmp->e.drawOn(r);
		tmp = tmp->next;
	}
}

//scorre la lista e controlla quali elementi sono da eliminare perchè si sono scontrati
enemies* goEnemy(enemies* head, int& n) {
	if (head == NULL)	
		return NULL;
	else {
		if (head->e.okCancel()) {
			n = n - 1;
			return goEnemy(head->next, n);
		}
		else {
			head->next = goEnemy(head->next, n);
			return head;
		}
	}
}

//scorre la lista controllando gli scontri
void onClashEnemy(enemies* head, int x, int y, int* score, int step, int* flashes, bool burst) {
	enemies* tmp = head;
	while (tmp != NULL) {
		if (tmp->e.clash(x, y)) {
			tmp->e.goCancel(true);
				*score -= tmp->e.okBroke();
				*flashes = 5;	
		}
		tmp = tmp->next;
	}
}

//controlla se è possibile inserire un elemento
bool okPoints(track r, int x) {
	if (r.map[0][x] == '.') // && r.map[0][x + 1] == '.' && r.map[0][x + 2] == '.')
		return true;
	else 
		return false;
}

//funzione per aggiungere un elemento alla lista
allPoints* addCoin(allPoints* head, int x, int isChoosen){
	if (head == NULL) {
		head = new allPoints;
		head->p = coin(x, -1, (isChoosen + 1) *1, 1, '@');
		head->next = NULL;
		return head;
	}
	else {
		head->next = addCoin(head->next, x, isChoosen);
		return head;
	}
}

//scorre la lista e chiama per ogni elemento il metodo moveTo per scorrere
void pointsOn(allPoints* head) {
	allPoints* tmp = head;
	while (tmp != NULL) {
		tmp->p.moveTo();
		tmp = tmp->next;
	}
}

//scorre la lista e stampa nella matrice della strada l'elemento
void inCoin(track& r, allPoints* head) {
	allPoints* tmp = head;
	while (tmp != NULL) {
		tmp->p.drawOn(r);
		tmp = tmp->next;
	}
}

//scorre la lista e controlla quali elementi occorre eliminare
allPoints* goCoin(allPoints* head, int& n) {
	if (head == NULL)	return NULL;
	else {
		if (head->p.okCancel()) {
			n = n - 1;
			return goCoin(head->next, n);
		}
		else {
			head->next = goCoin(head->next, n);
			return head;
		}
	}
}

//scorre la lista intera e controlla gli scontri
void onClashPoints(allPoints* head, int x, int y, int* score, int step, int* flashes, bool isCollect) {
	allPoints* tmp = head;
	while (tmp != NULL) {
		if (tmp->p.onClash(x, y)) {
	    tmp->p.goCancel(true); 
		*score += tmp->p.okBroke();		
		}
		tmp = tmp->next;
	}
}
