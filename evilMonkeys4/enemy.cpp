#include "enemy.h"
#include <math.h>
#include <stdlib.h>
#include "level.h"
#include "character.h"
#include <list>
using std::list;

Enemy::Enemy(Level* l, DrawEngine* de, int s_index, float x, float y,
	int i_lives) : Sprite(l, de, s_index, x, y, i_lives)
{
	goal = 0;
	classID = ENEMY_CLASSID;
}

bool Enemy::move(float x, float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);

	if (isValidLevelMove(xpos, ypos))
	{
		// make sure we dont run into any other enemy

		list<Sprite*>::iterator iter;
		for (iter = level->npc.begin(); iter != level->npc.end(); iter++)
		{
			if ((*iter) != this && (int)(*iter)->getX() == xpos && (int)(*iter)->getY() == ypos)
				return false;

		}

		// erase sprite
		erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;

		facingDirection.x = x;
		facingDirection.y = y;

		// draw sprite
		draw(pos.x, pos.y);

		return true;
	}
	return false;
}

void Enemy::idleUpdate(void)
{
	if (goal)
	{
		simulateAI();
	}
}

void Enemy::addGoal(Character* g)
{
	goal = g;
}

void Enemy::simulateAI(void)
{
	Vector goal_pos = goal->getPosition();
	Vector direction;

	direction.x = goal_pos.x - pos.x;
	direction.y = goal_pos.y - pos.y;

	float mag = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x = direction.x / (mag * 10);
	direction.y = direction.y / (mag * 10);

	if (!move(direction.x, direction.y))
	{
		while (!move(float(rand() % 3 - 1), float(rand() % 3 - 1)))
		{
		}
	}
}