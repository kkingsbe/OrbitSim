#include <vector>
#include "body.h"
#include "Datapoint.h"
#ifndef ENVIROMENT_H
#define ENVIROMENT_H

class Enviroment
{
	private:
		std::vector<Body> bodies; //A vector containing all of the bodies in the simulation
		std::vector<Datapoint> body1position;
		std::vector<Datapoint> body2position;
		double elapsedTime = 0.0; //The elapsed time in seconds
		const double G = 0.0000000000667408; //The gravitational constant
		double calculateGravitationalForce(Body body1, Body body2); //Calculates the gravitational force between two bodies
	public:
		std::vector<Body> getBodies() { return bodies; }; //Returns the bodies vector
		void addBody(Body body); //Adds a new body to the bodies vector
		void tick(double timestep); //Ticks the simulation
		void recordData();
		double getElapsedTime() { return elapsedTime; };
		void print();
};

#endif