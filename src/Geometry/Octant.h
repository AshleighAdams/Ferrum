#pragma once
#ifndef GEOMETRY_OCTANT_H
#define GEOMETRY_OCTANT_H

#include "Base.h"
#include "Util/Immutable.h"

/// A node with an octree with leaf nodes of a uniform depth.
template <class T>
class Octant : public Immutable
{

};

/// A branching node within an octree. 
template <class T>
class BranchOctant : public Octant<T>
{
public:
	~BranchOctant()
	{
		for(int i = 0; i < 8; i++)
		{
			this->children[i]->Unref();
		}
	}

	Octant<T>* children[8];
};

/// A leaf node within an octree.
template <class T>
class LeafOctant : public Octant<T>
{
public:
	~LeafOctant()
	{
		
	}

	T value;
};

#endif // GEOMETRY_OCTANT_H
