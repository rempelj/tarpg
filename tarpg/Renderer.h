#pragma once

#include "GameComponent.h"

class Renderer : public GameComponent
{
private:
	std::wstring graphic;
	int graphicSizeX;
	int graphicSizeY;

public:
	Renderer(GameObject* go);

	void Update();
	void Render();
	void SetGraphic(std::wstring graphic, int sizeX, int sizeY);
};