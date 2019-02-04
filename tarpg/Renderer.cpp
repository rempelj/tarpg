#include "Renderer.h"
#include "Screen.h"
#include "GameObject.h"

void Renderer::Update()
{

}

void Renderer::Render()
{
	Screen::Set(
		(int) std::round(gameObject->transform->x), 
		(int) std::round(gameObject->transform->y),
		'A'
	);
}