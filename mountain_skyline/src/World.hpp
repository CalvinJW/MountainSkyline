#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Base.hpp"
#include"House.hpp"
#include "Clouds.hpp"
#include <iostream>
#include <list>
#include <vector>
#include "Mountains.hpp"
#include "Cone.hpp"
#include "Cylinder.hpp"
#include "SunMoon.hpp"


class World {
public:
	Shape* list[7];
	// std::list<Shape*> ObjectList;
	// std::vector<Shape*>* ObjectVector;

	World();
	~World();
	void draw_world(); // draw all objects in the world
};

#endif
