
#pragma once
#ifndef WORLD_H
#define WORLD_H

#include "Entity/Entity.h"

class World
{
public:
	World();
	~World();
	void RenderWorld(sf::RenderWindow& App);
	void UpdateWorld(sf::RenderWindow& App, sf::Event& Event);
	void RemoveEntity(Entity* ToRemove); // Marks for deletion
private:
	void DeleteEntity(Entity* ToDelete); // Deletes
};

#endif // WORLD_H
