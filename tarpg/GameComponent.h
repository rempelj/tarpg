#pragma once

class GameObject;

class GameComponent
{
public:
	GameObject *gameObject;

	virtual void Update();
};