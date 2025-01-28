#include "drawEngine.h"
#include <Windows.h>
#include <iostream>

DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	// hide cursor visibility
	cursorVisibility(false);
}

DrawEngine::~DrawEngine()
{
	cursorVisibility(true);
	// set cursor visibility to true

	gotoxy(0, screenHeight);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return c;
	}
	else
	{
		return -1;
	}
}

void DrawEngine::deleteSprite(int index)
{
	// this we don't need
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	std::cout << ' ';
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	// go to the correct location
	gotoxy(posx, posy);
	// draw the image
	std::cout << spriteImage[index];
}

void DrawEngine::cursorVisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;

	cciInfo.bVisible = visibility;
	cciInfo.dwSize = 1;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cciInfo);
}

void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;
	pos.X = x;
	pos.Y = y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output_handle, pos);
}

