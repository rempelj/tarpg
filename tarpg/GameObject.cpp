#include "GameObject.h"
#include "Transform.h"
#include "Renderer.h"

void GameObject::Update()
{
	transform->gameObject = this;
	renderer->gameObject = this;

	components.push_back(transform);
	components.push_back(renderer);

}

template<typename T> GameComponent* GameObject::AddComponent()
{
	GameComponent *c = &((GameComponent)T());

	components.push_back(c);
	return c;
}