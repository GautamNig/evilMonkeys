#include "game.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

#define GAME_SPEED 33.33

bool Game::run(void)
{
	level = new Level(&drawArea, 30, 20);

	drawArea.createSprite(0, '$');
	//player = new Sprite(&drawArea, 0);
	player = new Character(&drawArea, 0);

	char key = ' ';
	frameCount = 0;
	startTime = timeGetTime();
	lastTime = 0;

	posx = 0;

	while (key != 'q')
	{
		while (!getInput(&key))
		{
			timerUpdate();
		}

		player->keyPress(key);
		//cout << "You Pressed: " << key << endl;
	}

	delete player;

	cout << timeGetTime() - startTime << "ms" << endl;
	cout << frameCount / ((timeGetTime() - startTime) / 1000) << "fps" << endl;
	cout << "End of Game" << endl;
	return true;
}

bool Game::getInput(char* c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true;
	}
	return false;
}

void Game::timerUpdate()
{
	double currentTime = timeGetTime() - lastTime;

	if (currentTime < GAME_SPEED)
		return;

	//drawArea.eraseSprite(posx, 5);
	//posx = (posx + 1) % 80;
	//drawArea.drawSprite(0, posx, 5);
	// 
	// Below we use while player was a sprite and we havnt added a character class yet.
	//player->move(1, 0);

	frameCount++;

	lastTime = timeGetTime();
}