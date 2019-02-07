#include "Collider.h"
#include "GameObject.h"
#include "Transform.h"
#include "Screen.h"

#include <windows.h>

std::vector<std::vector<Collider*>> Collider::colliderGrid;
int Collider::gridSizeX = 0;
int Collider::gridSizeY = 0;

namespace
{
	float lastFrameX;
	float lastFrameY;
}

Collider::Collider(GameObject *go) : GameComponent::GameComponent(go)
{
	lastFrameX = gameObject->transform->x;
	lastFrameX = gameObject->transform->y;

	sizeX = 1;
	sizeY = 1;
	offsetX = 0;
	offsetY = 0;

	AddToGrid();
}

Collider::~Collider()
{
	RemoveFromGrid();
}

void Collider::OnCollisionEnterInternal(Collider *col)
{
	Beep(523, 500);
}

void Collider::OnCollisionExitInternal(Collider *col)
{

}


bool Collider::Intersects(Collider *col)
{
	if (col != this && col->gameObject->scene == this->gameObject->scene)
	{
		int colAx1 = this->gameObject->transform->x + this->offsetX;
		int colAx2 = this->gameObject->transform->x + this->offsetX + this->sizeX;
		int colAy1 = this->gameObject->transform->y + this->offsetY;
		int colAy2 = this->gameObject->transform->y + this->offsetY + this->sizeY;

		int colBx1 = col->gameObject->transform->x + col->offsetX;
		int colBx2 = col->gameObject->transform->x + col->offsetX + col->sizeX;
		int colBy1 = col->gameObject->transform->y + col->offsetY;
		int colBy2 = col->gameObject->transform->y + col->offsetY + col->sizeY;

		if (colAx1 < colBx2 && colAx2 > colBx1 &&
			colAy1 > colBy2 && colAy2 < colBy1)
		{
			return true;
		}
	}

	return false;
}

void Collider::PreUpdate()
{
	if (gameObject->transform->x != lastFrameX || gameObject->transform->y != lastFrameY)
	{
		// Position changed. Refresh position on grid
		RemoveFromGrid();
		AddToGrid();
	}

	// remove old collisions
	for (int i = 0; i < collisions.size(); i++)
	{
		auto collision = collisions[i];

		if (!Intersects(collision))
		{
			// collision ended
			collisions.erase(collisions.begin() + i);
			OnCollisionExitInternal(collision);
		}

	}


	// update collisions 
	int numCells = sizeX * sizeY;
	auto myCells = new std::vector<Collider*>*[numCells];
	GetAllCellsAtCurrentPosition(myCells);

	for (int i = 0; i < numCells; i++)
	{
		auto cell = myCells[i];

		// trigger collision with all overlapped objects
		for (int j = 0; j < cell->size(); j++)
		{
			auto collision = (*cell)[j];

			if (Intersects(collision))
			{
				if (std::find(collisions.begin(), collisions.end(), collision) != collisions.end()) {
					// already overlapping
				}
				else {
					// just collided
					collisions.push_back(collision);
					OnCollisionEnterInternal(collision);
				}
			}

		}
	}

	delete[] myCells;

	lastFrameX = gameObject->transform->x;
	lastFrameX = gameObject->transform->y;
}

void Collider::Update()
{
	
}

void Collider::AddToGrid()
{
	int numCells = sizeX * sizeY;
	auto myCells = new std::vector<Collider*>*[numCells];
	GetAllCellsAtCurrentPosition(myCells);

	for (int i = 0; i < numCells; i++)
	{
		auto cell = myCells[i];
		cell->push_back(this);
	}

	delete[] myCells;
}

void Collider::RemoveFromGrid()
{
	int numCells = sizeX * sizeY;
	auto myCells = new std::vector<Collider*>*[numCells];
	GetAllCellsAtCurrentPosition(myCells);

	for (int i = 0; i < numCells; i++) 
	{
		auto cell = myCells[i];
		if (cell->size() > 0)
		{
			auto iter = std::find(cell->begin(), cell->end(), this);	// search cell for this collider
			cell->erase(iter);
		}
		
	}
	
	delete[] myCells;
}

void Collider::GetAllCellsAtCurrentPosition(std::vector<Collider*> *results[])
{
	int startPosX = gameObject->transform->x + offsetX;
	int startPosY = gameObject->transform->y + offsetY;
	int endPosX = startPosX + sizeX;
	int endPosY = startPosY + sizeY;

	// resize grid if needed
	{
		int requiredGridSize = endPosX*endPosY;
		int currentGridSize = Collider::gridSizeX * Collider::gridSizeY;

		if (currentGridSize < requiredGridSize)
		{
			Collider::gridSizeX = endPosX;
			Collider::gridSizeY = endPosY;

			Collider::colliderGrid.resize(requiredGridSize);
		}
	}

	// retrieve all cells at this object's position
	int i = 0;
	for (int x = startPosX; x < endPosX; x++)
	{
		for (int y = startPosY; y < endPosY; y++)
		{
			if (x < 0 || y < 0)
			{
				// out of bounds
				continue;
			}

			if (x * y >= Collider::colliderGrid.size())
			{
				// out of bounds
				continue;
			}

			auto cell = Collider::colliderGrid[y * Collider::gridSizeX + x];
			results[i] = &cell;
			i++;
		}
	}
}