#include "GameObject.h"
#include "Transform.h"


void GameObject::Update()
{
//	transform.gameObject = this;
	components.push_back(transform);
}