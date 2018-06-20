#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Ship.h"

using std::vector;

struct Cell_
{
	char visualRepresentation;
	int shipId;
	int shipCellNum;
	bool wasHit;
};

class Board
{
private:
	const int size_ = 10;
	int shipCount_;
	vector<vector<Cell_*>> board_;
	vector<Ship*> ships_;
public:
	Board();
	int addShip(Ship* ship);
	int hit(int x, int y);
	bool checkLose();

	void printShipId();
	void printShipCellNum();
	void printHits();
	friend std::ostream& operator<< (std::ostream&, Board const&);

	Cell_* getBoard(int x, int y);
	Ship* getShip(int n);
	int getShipCount();
};

#endif // !BOARD_H
