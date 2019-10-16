#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include "enviroment.h"
#include "body.h"

int main() {
	Enviroment env;
	int1024_t earthMass("5972000000000000000000000");
	Body earth(earthMass, 0, 0);
	Body body2(1, 5, 5);
	env.addBody(earth);
	env.addBody(body2);
	while (env.getElapsedTime() <= 60 * 60)
	{
		//env.print();
		env.tick(0.1);
	}
	env.recordData();
}