#include "level.h"
#include "character.h"
#include <stdlib.h>

Level::Level(DrawEngine* de, int w, int h)
{
	drawArea = de;
	width = w;
	height = h;

	player = 0;

	// create memory for our level
	level = new char* [width];
	for (size_t i = 0; i < width; i++)
	{
		level[i] = new char[height];
	}

	// create the level
	createLevel();

	drawArea->setMap(level);
}

Level::~Level()
{
	for (size_t i = 0; i < width; i++)
	{
		delete[] level[i];
	}
	delete[] level;
}

void Level::createLevel(void)
{
	for (size_t x= 0; x< width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
			{
				level[x][y] = TILE_WALL;
			}
			else
			{
				int random = rand() % 100;
				if (random < 90 || (x < 3 && y < 3))
					level[x][y] = TILE_EMPTY;
				else
					level[x][y] = TILE_WALL;
			}
		}
	}
}

void Level::draw(void)
{
	// we need to draw level
	drawArea->drawBackground();
}

void Level::addPlayer(Character* p)
{
	player = p;
}

bool Level::keyPress(char c)
{
	if (player)
	{
		if (player->keyPress(c))
		{
			return true;
		}
	}
	return false;
}

void Level::update(void)
{
	// here we deal with fireball moving
}