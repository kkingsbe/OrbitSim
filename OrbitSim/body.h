#include "Datapoint.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

#ifndef BODY_H
#define BODY_H

using namespace boost::multiprecision;

class Body
{
	private:
		int1024_t mass = 0; //The mass in kg
		double x = { 0.0 }; //The x position in m
		double y = { 0.0 }; //The y position in m
		double vx = 0.0; //The x component of the velocity in m/s
		double vy = 0.0; //The y component of the velocity in m/s
		double ax = 0; //The x component of the acceleration in m/s^2
		double ay = 0.0; //The y component of the acceleration in m/s^2
		std::vector<Datapoint> position;
	public:
		Body(int1024_t mass, double x, double y);
		void setX(double x) { this->x = x; };
		void setY(double y) { this->y = y; };
		void setVX(double vx) { this->vx = vx; };
		void setVY(double vy) { this->vy = vy; };
		void setAX(double ax) { this->ax = ax; };
		void setAY(double ay) { this->ay = ay; };
		void recordPosition(Datapoint datapoint) { position.push_back(datapoint); };

		double getX() { return x; };
		double getY() { return y; };
		double getVX() { return vx; };
		double getVY() { return vy; };
		double getAX() { return ax; };
		double getAY() { return ay; };
		int1024_t getMass() { return mass; };
		std::vector<Datapoint> getPosition() { return position; };
};
#endif