#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Update();
	void UpdateMatrix();
	Vector Position;
	Angle Orientation; // TODO: Shitty name
};


#endif // CAMERA_H
