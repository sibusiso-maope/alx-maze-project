#include "../headers/header.h"

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
*/

void drawRect(int x, int y, int width, int height, color_t color)
{
	int k, l;

	for (k = x; k <= (x + width); k++)
		for (l = y; l <= (y + height); l++)
			drawPixel(k, l, color);
}

/**
 * drawLine - draw a line
 * @x0: x coordinate init
 * @y0: y coordinate init
 * @x1: x coordinate init
 * @y1: y coordinate end
 * @color: pixel color
*/

void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float xIncrement, yIncrement, currentX, currentY;
	int k, longestSideLength, deltaX,  deltaY;

	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	currentX = x0;
	currentY = y0;

	for (k = 0; k < longestSideLength; k++)
	{
		drawPixel(round(currentX), round(currentY), color);
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
