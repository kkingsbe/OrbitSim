#define _USE_MATH_DEFINES

#include "enviroment.h"
#include "Force.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

void Enviroment::addBody(Body body)
{
	bodies.push_back(body);
}

void Enviroment::tick(double timestep)
{
	elapsedTime += timestep;
	for (int i = 0; i < bodies.size(); i++)
	{
		double Fnetx = 0.0;
		double Fnety = 0.0;
		for (int j = 0; j < bodies.size(); j++)
		{
			if (j == i) continue;
			double xDis = bodies[j].getX() - bodies[i].getX();
			double yDis = bodies[j].getY() - bodies[i].getY();
			bool thirdQuadrant = xDis < 0 && yDis < 0;
			if (!thirdQuadrant)
			{
				Fnetx += calculateGravitationalForce(bodies[i], bodies[j]) * cos(atan(yDis / xDis));
				Fnety += calculateGravitationalForce(bodies[i], bodies[j]) * sin(atan(yDis / xDis));
			}
			else
			{
				Fnetx += calculateGravitationalForce(bodies[i], bodies[j]) * cos(atan(yDis / xDis) + M_PI);
				Fnety += calculateGravitationalForce(bodies[i], bodies[j]) * sin(atan(yDis / xDis) + M_PI);
			}
		}
		bodies[i].setAX(Fnetx / bodies[i].getMass());
		bodies[i].setAY(Fnety / bodies[i].getMass());

		bodies[i].setVX(bodies[i].getVX() + (timestep * bodies[i].getAX()));
		bodies[i].setVY(bodies[i].getVY() + (timestep * bodies[i].getAY()));

		bodies[i].setX(bodies[i].getX() + bodies[i].getVX() * (timestep + bodies[i].getAX() * pow(bodies[i].getAX(), 2)));
		bodies[i].setY(bodies[i].getY() + bodies[i].getVY() * (timestep + bodies[i].getAY() * pow(bodies[i].getAY(), 2)));

		/*
		bodies[i].setAX(Fnetx / bodies[i].getMass());
		bodies[i].setAY(Fnety / bodies[i].getMass());
		bodies[i].setX((2 * bodies[i].getX()) - bodies[i].getX() + bodies[i].getAX() * pow(timestep, 2));
		bodies[i].setY((2 * bodies[i].getY()) - bodies[i].getY() + bodies[i].getAY() * pow(timestep, 2));
		*/

		Datapoint point;
		point.x = bodies[i].getX();
		point.y = bodies[i].getY();
		bodies[i].recordPosition(point);
	}
}

double Enviroment::calculateGravitationalForce(Body body1, Body body2)
{
	double r = sqrt(pow((body1.getX() - body2.getX()), 2) + pow((body1.getY() - body2.getY()), 2));
	double f = G * ((body1.getMass() * body2.getMass()) / pow(r, 2));
	return abs(f);
}

void Enviroment::recordData()
{
	std::ofstream f;
	f.open("body1.csv");
	std::vector<Datapoint> position = bodies[0].getPosition();
	for (Datapoint datapoint : position)
	{
		f << datapoint.x << " " << datapoint.y << "\n";
	}
	f.close();

	f.open("body2.csv");
	std::vector<Datapoint> position2 = bodies[1].getPosition();
	for (Datapoint datapoint : position2)
	{
		f << datapoint.x << " " << datapoint.y << "\n";
	}
	f.close();
}

void Enviroment::print()
{
	for (int x = 0; x < bodies.size(); x++)
	{
		Body body = bodies[x];
		std::cout << "------------\n";
		std::cout << "Body " << x << "\n";
		std::cout << "Mass: " << body.getMass() << "\n";
		std::cout << "X: " << body.getX() << "\n";
		std::cout << "Y: " << body.getY() << "\n";
	}
}