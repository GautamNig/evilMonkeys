#include "level.h"
#include "character.h"
#include <stdlib.h>
#include "enemy.h"

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

	for (iter = npc.begin(); iter != npc.end(); iter++)
	{
		(*iter)->idleUpdate();
		if ((*iter)->isAlive() == false)
		{
			Sprite* temp = *iter;

			// After we decrememnt pointer, we aren't pointing at it anymore but temp is still pointing at it.
			// And hence we can safely delete it using temp.
			iter--;
			delete temp;
			npc.remove(temp);
		}
	}
}

void Level::addEnemies(int num)
{
	int i = num;
	while (i > 0)
	{
		int xpos = int((float(rand() % 100) / 100) * (width - 2) + 1);
		int ypos = int((float(rand() % 100) / 100) * (height - 2) + 1);

		if (level[xpos][ypos] != TILE_WALL)
		{
			Enemy* temp = new Enemy(this, drawArea, SPRITE_ENEMY, float(xpos), float(ypos));
			temp->addGoal(player);
			addNPC((Sprite*)temp);

			i--;
		}
	}
}

void Level::addNPC(Sprite* spr)
{
	npc.push_back(spr);
}