#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <iostream>
#include <map>

using std::string; using std::cout; using std::cin; using std::endl;
using std::map;


class Ship
{
private:
	int xCoord_;
	int yCoord_;
	bool orientation_; //true - horizontal, false - vertical
	int length_;
	bool isSunk_;
	string type_;
public:
	Ship(int xCoord, int yCoord, int orientation, string type);

	void hit(int cell);
	bool *hits_;

	Ship& operator= (Ship const&);

	int getXCoord();
	int getYCoord();
	bool getOrientation();
	int getLength();
	bool getIsSunk();
	string getType();
};

#endif // !SHIP_H
