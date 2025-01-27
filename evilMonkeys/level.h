#include "drawEngine.h"
//#include "character.h"
#ifndef LEVEL_H
#define LEVEL_H

class Character;
enum
{
	TILE_EMPTY,
	TILE_WALL
};

class Level
{
public:
	Level(DrawEngine* de, int width = 30, int height = 20);
	~Level();

	void addPlayer(Character* p);
	void update(void);
	void draw(void);
	bool keyPress(char c);

	friend class Sprite;

protected:
	void createLevel();

private:
	int width;
	int height;

	char** level;
	Character* player;
	DrawEngine* drawArea;
};

#endif