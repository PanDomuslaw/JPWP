#include "Ship.h"

map<string, int> lengthOfType_ =
{
	{ "carrier", 5 },{ "battleship", 4 },{ "cruiser", 3 },{ "submarine", 3 },{ "destroyer", 2 }
};

Ship::Ship(int xCoord, int yCoord, int orientation, string type)
	: xCoord_(xCoord), yCoord_(yCoord), orientation_(orientation), type_(type)
{
	this->length_ = lengthOfType_[type];
	this->isSunk_ = false;
	this->hits_ = new bool[5];
	for (int i = 0; i < length_; i++)
	{
		this->hits_[i] = false;
	}
}

void Ship::hit(int cell)
{
	this->hits_[cell] = true;
}  

Ship& Ship::operator= (Ship const& second)
{
	this->xCoord_ = second.xCoord_;
	this->yCoord_ = second.yCoord_;
	this->orientation_ = second.orientation_;
	this->length_ = second.length_;
	this->hits_ = second.hits_;
	this->isSunk_ = second.isSunk_;
	this->type_ = second.type_;
	return *this;
}

int Ship::getXCoord()
{
	return xCoord_;
}

int Ship::getYCoord()
{
	return yCoord_;
}

bool Ship::getOrientation()
{
	return orientation_;
}

int Ship::getLength()
{
	return length_;
}

bool Ship::getIsSunk()
{
	for (int i = 0; i < length_; i++)
	{
		if (hits_[i] == false)
		{
			break;
		}
		this->isSunk_ = true;
	}
	return isSunk_;
}

string Ship::getType()
{
	return type_;
}