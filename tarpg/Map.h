#pragma once

#include <string>

class Map
{
private:
	std::wstring layout;
	int sizeX;
	int sizeY;

public:
	const int TILE_WIDTH = 12;
	const int TILE_HEIGHT = 6;

	void SetLayout(std::wstring layout, int mapSizeX, int mapSizeY);
	void ApplyToActiveScene();
};