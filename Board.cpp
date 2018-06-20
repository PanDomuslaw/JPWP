#include "Board.h"

Board::Board()
{
	for (int i = 0; i < size_; i++)
	{
		vector<Cell_*> tmpVector;
		for (int j = 0; j < size_; j++)
		{
			Cell_* tmpCell = new Cell_;
			*tmpCell = { '.',0 ,0, false };
			tmpVector.push_back(tmpCell);
		}
		board_.push_back(tmpVector);
	}
	shipCount_ = 0;
}

int Board::addShip(Ship* ship)
{
	shipCount_++;
	ships_.push_back(ship);
	int id = shipCount_;
	int x = ships_[id - 1]->getXCoord();
	int y = ships_[id - 1]->getYCoord();
	bool orient = ships_[id - 1]->getOrientation();
	int length = ships_[id - 1]->getLength();

	if (orient)
	{
		for (int i = 0; i < length; i++)
		{
			if (board_[x + i][y]->shipId != 0)
			{
				return -1;
			}
		}
		for (int i = 0; i < length; i++)
		{
			board_[x + i][y]->shipId = id;
			board_[x + i][y]->shipCellNum = i + 1;
			board_[x + i][y]->visualRepresentation = 'X';
		}
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			if (board_[x][y + i]->shipId != 0)
			{
				return -1;
			}
		}
		for (int i = 0; i < length; i++)
		{
			board_[x][y + i]->shipId = id;
			board_[x][y + i]->shipCellNum = i + 1;
			board_[x][y + i]->visualRepresentation = 'X';
		}
	}
	return 0;
}

int Board::hit(int x, int y)
{
	if (board_[x][y]->wasHit)
		return -1;
	else
	{
		board_[x][y]->wasHit = true;
		int id = board_[x][y]->shipId;
		if (id != 0)
		{
			int cellNum = board_[x][y]->shipCellNum;
			ships_[id-1]->hit(cellNum-1);
			ships_[id - 1]->hits_[cellNum-1];
			if (ships_[id-1]->getIsSunk())
			{
				cout << "You've sunk the ship\n";
				cout << ships_[id-1]->getIsSunk() << endl;
				return 2;
			}
			else
			{
				cout << ships_[id-1]->getIsSunk() << endl;
				return 1;
			}
		}
		else
			return 0;
	}
}

bool Board::checkLose()
{
	for (int i = 0; i < shipCount_; i++)
	{
		if (ships_[i]->getIsSunk() == false)
		{
			return false;
		}
	}
	return true;
}

void Board::printShipId()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << board_[j][i]->shipId;
		}
		cout << '\n';
	}
}

void Board::printShipCellNum()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << board_[j][i]->shipCellNum;
		}
		cout << '\n';
	}
}

void Board::printHits()
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << board_[j][i]->wasHit;
		}
		cout << '\n';
	}
}

std::ostream& operator<< (std::ostream& out, Board const& board)
{
	for (int i = 0; i < board.size_; i++)
	{
		for (int j = 0; j < board.size_; j++)
		{
			if (board.board_[j][i]->wasHit)
				out << board.board_[j][i]->visualRepresentation;
			else
				out << ' ';
		}
		out << '\n';
	}
	return out;
}

Cell_* Board::getBoard(int x, int y)
{
	return board_[x][y];
}

Ship* Board::getShip(int n)
{
	return ships_[n];
}

int Board::getShipCount()
{
	return shipCount_;
}
