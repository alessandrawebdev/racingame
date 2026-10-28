#ifndef ENGINE_H
#define ENGINE_H
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include "car.hpp"
#include "track.hpp"
#include "basic.hpp"
#include "bomb.hpp"
#include "enemy.hpp"
#include "coins.hpp"
#include "lists.hpp"

using namespace std;

//file header di engine.cpp che contiene le definizioni e prototipi del motore di gioco "engine"

class engine {
	private:
		int choice, points, tot, level, flashes, gogo;
		int maxOb, numbOb;
		track road;
		car player;
		bool quit;
		bool isBurst, isCollect;
		bombs* headBomb;
		enemies* headEnemy;
		allPoints* headCoin;
	public:
		engine();
		engine(int canc); 
		void run();
		void start();
		void setMap();
		bool restart();
};
#endif