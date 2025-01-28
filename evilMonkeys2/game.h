#include "drawEngine.h"
#include "sprite.h"
#include "character.h"
#include "level.h"
#ifndef GAME_H
#define GAME_H

class Game
{
public:
	bool run(void);


protected:
	bool getInput(char* c);
	void timerUpdate(void);

private:
	double frameCount;
	double startTime;
	double lastTime;

	int posx;

	DrawEngine drawArea;
	//Sprite* player;
	Level* level;
	Character* player;
};


#endif