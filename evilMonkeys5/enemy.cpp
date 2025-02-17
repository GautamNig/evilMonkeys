#include "enemy.h"
#include "character.h"
#include "level.h"
#include <math.h>
#include <stdlib.h>

Enemy::Enemy(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives) :
	Sprite(l, de, s_index, x, y, i_lives)
{
	goal = 0;
	classID = ENEMY_CLASSID;
}
bool Enemy::move(float x, float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);

	if(isValidLevelMove(xpos, ypos))
	{
		//make sure if we don't run into any other enemies
		list <Sprite *>::iterator Iter;

		for(Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			if((*Iter) != this && (int)(*Iter)->getX() == xpos && (int)(*Iter)->getY() == ypos)
			{
				return false;
			}

		}


		erase(pos.x, pos.y);
		pos.x += x;
		pos.y += y;

		facingDirection.x = x;
		facingDirection.y = y;

		draw(pos.x, pos.y);

		if((int)goal->getX() == xpos && (int)goal->getY() == ypos)
			goal->addLives(-1);

		return true;
	}

		return false;
}

void Enemy::idleUpdate(void)
{
	if(goal)
		simulateAI();
}

void Enemy::addGoal(Character *g)
{
	goal = g;
}

void Enemy::simulateAI(void)
{
	vector goal_pos = goal->getPosition();
	vector direction;

	direction.x = goal_pos.x - pos.x;
	direction.y = goal_pos.y - pos.y;

	float mag = sqrt(direction.x * direction.x + direction.y * direction.y);

	direction.x = direction.x / (mag * 10);
	direction.y = direction.y / (mag * 10);

	if(!move(direction.x, direction.y))
	{
		while(!move(float(rand() % 3 - 1), float(rand() % 3 - 1)))
		{
		}
	}
}