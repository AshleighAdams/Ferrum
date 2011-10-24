
#include "Camera/Camera.h"

#include "GL/gl.h"

Camera::Camera()
{
	this->Position.X = 0.;
	this->Position.Y = 0.;
	this->Position.Z = 0.;
	
	this->Orientation.Pitch = 0.;
	this->Orientation.Yaw = 0.;
	this->Orientation.Roll = 0.;
}

Camera::Update(sf::RenderWindow& App)
{
}

Camera::UpdateMatrix()
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef( m_xTransform, m_yTransform, m_zTransform );
	glRotatef( m_xRotation, 1.0f, 0.0f, 0.0f );
	glRotatef( m_yRotation, 0.0f, 1.0f, 0.0f );
	glRotatef( m_zRotation, 0.0f, 0.0f, 1.0f );
}

Camera::~Camera()
{
}
