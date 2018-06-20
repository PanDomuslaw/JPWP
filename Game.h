#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board.h"

#include <fstream>

class Game
{
private:
	Board* Player1_ = new Board;
	Board* Player2_ = new Board;

	int turn;
public:
	void loadGame(string name);
	//void saveGame(string name);

	int player1Turn();
	int player2Turn();

	void printPlayer1();
	void printPlayer2();

	Board* getPlayer1();
	Board* getPlayer2();
};

#endif // !GAME_H
