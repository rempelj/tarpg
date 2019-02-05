#pragma once

#include "GameComponent.h"

class PlayerCharacter : public GameComponent
{
public:
	PlayerCharacter(GameObject* go);
	void Update();
};