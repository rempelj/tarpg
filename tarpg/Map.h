#pragma once

#include <string>

class Map
{
private:
	std::wstring layout;
	int sizeX;
	int sizeY;

public:
	static const int TILE_WIDTH = 12;
	static const int TILE_HEIGHT = 6;

	int GetSizeX() { return sizeX; }
	int GetSizeY() { return sizeY; }
	std::wstring GetLayoutData() { return layout; }

	void SetLayout(std::wstring layout, int mapSizeX, int mapSizeY);
	void ApplyToActiveScene();
};