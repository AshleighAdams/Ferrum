#pragma once
#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
public:
	Angle()
	{
		this->Pitch = 0.;
		this->Yaw = 0.;
		this->Roll = 0.;
	}
	Angle(double Pitch, double Yaw, double Roll)
	{
		this->Pitch = Pitch;
		this->Yaw = Yaw;
		this->Roll = Roll;
	}
	double Pitch;
	double Yaw;
	double Roll;
};


#endif // ANGLE_H
