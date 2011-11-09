#include "Base.h"
#include "Camera/Camera.h"

Camera::Camera()
{
	this->Position.X = 0.;
	this->Position.Y = 0.;
	this->Position.Z = 0.;
	
	this->Orientation.Pitch = 0.;
	this->Orientation.Yaw = 0.;
	this->Orientation.Roll = 0.;
	
	
}

Camera::~Camera()
{
}

void Camera::Update()
{
	// Not yet implemented.
}

void Camera::UpdateMatrix()
{
	
}
