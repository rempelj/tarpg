#pragma once

#include <vector>

#include "GameComponent.h"

class Collider : public GameComponent
{
private:
	static std::vector<std::vector<Collider*>> colliderGrid;
	static int gridSizeX;
	static int gridSizeY;

	std::vector<Collider*> collisions;

	void RemoveFromGrid();
	void AddToGrid();

	void OnCollisionEnterInternal(Collider *col);
	void OnCollisionExitInternal(Collider *col);


public:
	int sizeX;
	int sizeY;
	int offsetX;	// spaces right from the bottom left corner
	int offsetY;	// spaces up from the bottom left corner

	Collider(GameObject* go);
	~Collider();

	void PreUpdate();
	void Update();

	void GetAllCellsAtCurrentPosition(std::vector<Collider*>* results[]);
	bool Intersects(Collider *col);
};