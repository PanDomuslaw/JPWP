#include "Game.h"

int main()
{
	Game game1;
	game1.loadGame("Save");

	int cond1 = 0;
	int cond2 = 0;

	while (cond1 == false && cond2 == false)
	{
		cond1 = game1.player1Turn();
		cond2 = game1.player2Turn();
	}

	if (cond1 == 1)
		cout << "Player1 wins";
	if (cond2 == 1)
		cout << "Player2 wins";

	/*Board b1; 
	//cout << b1 << endl;
	Ship s1(3, 4, true, "cruiser");
	b1.addShip(&s1);
	b1.printShipId();
	//cout << b1 << endl;
	Ship s2(7, 2, false, "carrier");
	b1.addShip(&s2);
	b1.printShipId();
	//cout << b1 << endl;*/

	system("PAUSE");
	return 0;
}