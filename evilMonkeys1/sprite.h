#include "drawEngine.h"
#ifndef  SPRITE_H
#define SPRITE_H

enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID
};

struct Vector
{
	float x;
	float y;
};

class Sprite
{
public:
	Sprite(DrawEngine* de, int s_index, float x = 1, float y = 1, int i_lives = 1);
	~Sprite();

	Vector getPosition(void);
	float getX(void);
	float getY(void);

	virtual void addLives(int num = 1);
	int getLives(void);
	bool isAlive(void);

	virtual bool move(float x, float y);

protected:
	DrawEngine* drawArea;
	Vector pos;
	int spriteIndex;
	int numLives;

	int classID;

	Vector facingDirection;
	void draw(float x, float y);
	void erase(float x, float y);

private:

};


#endif // ! SPRITE_H
