#pragma once

class GameObject;

class GameComponent
{
public:
	GameObject *gameObject;

	GameComponent(GameObject* go);

	virtual void PreUpdate();
	virtual void Update();
	virtual void LateUpdate();
};