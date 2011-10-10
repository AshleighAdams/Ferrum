
#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "Base.h"

class Entity
{
public:
	virtual Entity() {}
	virtual ~Entity() {}
	virtual std::string GetClassName() = 0;
};

#endif // ENTITY_H
