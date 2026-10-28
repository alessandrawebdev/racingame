#ifndef LISTS_H
#define LISTS_H
#include <stdbool.h>
#include "enemy.hpp"
#include "track.hpp"
#include "car.hpp"
#include "coins.hpp"
#include "bomb.hpp"

struct bombs {
	bomb c;
	bombs* next;
};

struct enemies {
	enemy e;
	enemies* next;
};

struct allPoints {
	coin p;
	allPoints* next;
};

bombs* addBomb(bombs* head, int x, int isChoosen);
enemies* addEnemy(enemies* head, int x, int isChoosen);
allPoints* addCoin(allPoints* head, int x, int isChoosen);

bool okBomb(track r, int x);
void inBomb(track& r, bombs* head);
void bombOn(bombs* head);
void onClashBomb(bombs* head, int x, int y, int* score, int step, int* flashes, bool burst);
bombs* goBomb(bombs* head, int& n);

bool okEnemy(track r, int x);
void inEnemy(track& r, enemies* head);
void enemyOn(enemies* head);
void onClashEnemy(enemies* head, int x, int y, int* score, int step, int* flashes, bool burst);
enemies* goEnemy(enemies* head, int& n);

bool okPoints(track r, int x);
void inCoin(track& r, allPoints* head);
void pointsOn(allPoints* head);
void onClashPoints(allPoints* head, int x, int y, int* score, int step, int* flashes, bool isCollect);
allPoints* goCoin(allPoints* head, int& n);

#endif