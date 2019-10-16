#define _USE_MATH_DEFINES

#include "Force.h"
#include <cmath>

double Force::getMagnitude()
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Force::getXComponent()
{
	return x;
}

double Force::getYComponent()
{
	return y;
}

double Force::getTheta()
{
	return atan(y/x) * (180 / M_PI);
}

void Force::setMagnitude(double magnitude)
{
	double theta = getTheta();
	x = magnitude * cos(theta * (M_PI / 180));
	y = magnitude * sin(theta * (M_PI / 180));
}

void Force::setXComponent(double x)
{
	this->x = x;
}

void Force::setYComponent(double y)
{
	this->y = y;
}

void Force::setTheta(double theta)
{
	double magnitude = getMagnitude();
	x = magnitude * cos(theta * (M_PI / 180));
	y = magnitude * sin(theta * (M_PI / 180));
}
