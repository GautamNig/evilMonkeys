#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H

class DrawEngine
{
public:
	DrawEngine(int xSize = 30, int ySize = 20);
	int createSprite(int index, char c);
	void deleteSprite(int index);
	void eraseSprite(int posx, int posy);
	void drawSprite(int index, int posx, int posy);
	void setMap(char**);

	void createBackgroundTile(int index, char c);

	void drawBackground(void);
	~DrawEngine();

protected:
	char** map;
	int screenWidth, screenHeight;
	char spriteImage[16];
	char tileImage[16];

private:
	void gotoxy(int x, int y);
	void cursorVisibility(bool visibility);
};



#endif // !DRAW_ENGINE_H

