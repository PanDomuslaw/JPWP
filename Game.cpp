#include "Game.h"

//void Game::saveGame(string name)
/*{
	cout << "Saving...";

	string fileName = name + ".txt";
	std::fstream SaveFile;
	SaveFile.open(fileName.c_str(), std::fstream::out);

	if (SaveFile.is_open())
	{
		for (int i = 0; i < Player1_->getShipCount(); i++)
		{
			SaveFile << Player1_->getShip(i)->getType() << endl;
			SaveFile << Player1_->getShip(i)->getXCoord() << ' ';
			SaveFile << Player1_->getShip(i)->getYCoord() << ' ';
			SaveFile << Player1_->getShip(i)->getOrientation() << endl;
		}
		for (int i = 0; i < Player2_->getShipCount(); i++)
		{
			SaveFile << Player2_->getShip(i)->getType() << endl;
			SaveFile << Player2_->getShip(i)->getXCoord() << ' ';
			SaveFile << Player2_->getShip(i)->getYCoord() << ' ';
			SaveFile << Player2_->getShip(i)->getOrientation() << endl;
		}
	}
	else
	{
		cout << "Error. Cannot save file";
	}
	cout << "done!\n";
	SaveFile.close();
}*/

void Game::loadGame(string name)
{
	cout << "Saving...";

	int shipCount = 5;

	string fileName = name + ".txt";
	std::fstream SaveFile;
	SaveFile.open(fileName.c_str(), std::fstream::in);

	if (SaveFile.is_open())
	{
		for (int i = 0; i < shipCount; i++)
		{
			int x, y;
			string t;
			bool o;
			SaveFile >> t;
			SaveFile >> x;
			SaveFile >> y;
			SaveFile >> o;
			Ship* ship = new Ship(x - 1, y - 1, o, t);
			if (Player1_->addShip(ship) == -1)
			{
				cout << "Player1 - Wrong placement of " << ship->getType() << endl;
			}
		}
		for (int i = 0; i < shipCount; i++)
		{
			int x, y;
			string t;
			bool o;
			SaveFile >> t;
			SaveFile >> x;
			SaveFile >> y;
			SaveFile >> o;
			Ship* ship = new Ship(x - 1, y - 1, o, t);
			if (Player2_->addShip(ship))
			{
				cout << "Player2 - Wrong placement of " << ship->getType() << endl;
			}
		}
	}
	else
	{
		cout << "Error. Cannot save file";
	}
	cout << "done!\n";
	SaveFile.close();
}

int Game::player1Turn()
{
	int x, y;
	cout << "Type x coordinate: ";
	cin >> x;
	cout << "Type y coordinate: ";
	cin >> y;
	int r = Player2_->hit(x, y);

	if (r == -1)
	{
		cout << "Already shot \n";
		player1Turn();
	}
	else if (r == 0)
	{
		cout << "Missed\n";
	}
	else if (r == 1)
	{
		cout << "Good shot!\n";
		player1Turn();
	}
	else if (r == 2)
	{
		cout << "You sunk opponent ship!\n";
		player1Turn();
	}
	printPlayer1();

	if (Player2_->checkLose())
		return 1;
	return 0;
}

int Game::player2Turn()
{
	int x, y;
	cout << "Type x coordinate: ";
	cin >> x;
	cout << "Type y coordinate: ";
	cin >> y;
	int r = Player1_->hit(x, y);

	if (r == -1)
	{
		cout << "Already shot \n";
		player2Turn();
	}
	else if (r == 0)
	{
		cout << "Missed\n";
	}
	else if (r == 1)
	{
		cout << "Good shot!\n";
		player2Turn();
	}
	else if (r == 2)
	{
		cout << "You sunk opponent ship!\n";
		player2Turn();
	}
	printPlayer2();

	if (Player2_->checkLose())
		return 1;
	return 0;
}

void Game::printPlayer1()
{
	cout << *Player2_;
	cout << "Player 1 ships: \n";
	for (int i = 0; i < Player1_->getShipCount(); i++)
	{
		Ship* tmp = Player1_->getShip(i);
		cout << tmp->getType() << ": ";
		for (int j = 0; j < tmp->getLength(); j++)
		{
			cout << tmp->hits_[j];
		}
		cout << endl;
	}
}

void Game::printPlayer2()
{
	cout << *Player1_;
	cout << "Player 2 ships: \n";
	for (int i = 0; i < Player2_->getShipCount(); i++)
	{
		Ship* tmp = Player2_->getShip(i);
		cout << tmp->getType() << ": ";
		for (int j = 0; j < tmp->getLength(); j++)
		{
			cout << tmp->hits_[j];
		}
		cout << endl;
	}
}

Board* Game::getPlayer1()
{
	return Player1_;
}

Board* Game::getPlayer2()
{
	return Player2_;
}