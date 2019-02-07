#pragma once

#include <vector>

#include "GameComponent.h"

class Collider : public GameComponent
{
	struct CellContents
	{
		std::vector<Collider*> colliders;
	};

	struct CellInfo
	{
		Collider::CellContents contents;
		int x;
		int y;

		CellInfo(Collider::CellContents contents, int x, int y)
		{
			this->contents = contents;
			this->x = x;
			this->y = y;
		}
	};

private:
	static std::vector<CellContents> colliderGrid;	// a grid reprsented as a 1d array
	static int gridSizeX;
	static int gridSizeY;

	float lastFrameX;
	float lastFrameY;

	std::vector<CellInfo> allCellsAtCurrentPosition;
	std::vector<CellInfo> allCellsAtLastPosition;

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
	void LateUpdate();

	std::vector<CellInfo> GetAllCellsAtCurrentPosition();
	bool Intersects(Collider *col);

};