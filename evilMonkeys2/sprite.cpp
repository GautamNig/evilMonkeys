#include "sprite.h"

Sprite::Sprite(DrawEngine* de, int s_index, float x, float y, int i_lives)
{
	drawArea = de;
	pos.x = x;
	pos.y = y;
	spriteIndex = s_index;
	numLives = i_lives;

	facingDirection.x = 1;
	facingDirection.y = 0;

	classID = SPRITE_CLASSID;
}

Sprite::~Sprite()
{
	// erase the dying sprite
	erase(pos.x, pos.y);
}

Vector Sprite::getPosition(void)
{
	return pos;
}

float Sprite::getX(void)
{
	return pos.x;
}

float Sprite::getY(void)
{
	return pos.y;
}

void Sprite::addLives(int num)
{
	numLives += num;
}
int Sprite::getLives(void)
{
	return numLives;
}
bool Sprite::isAlive(void)
{
	return (numLives > 0);
}

bool Sprite::move(float x, float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);

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

void Sprite::draw(float x, float y)
{
	drawArea->drawSprite(spriteIndex, (int)x, (int)y);
}
void Sprite::erase(float x, float y)
{
	drawArea->eraseSprite((int)x, (int)y);
}


