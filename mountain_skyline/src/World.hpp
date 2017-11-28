#ifndef CWORLD_HPP
#define CWORLD_HPP

#include "Pyramid.hpp"
#include"House.hpp"
#include "Mesh.hpp"
#include <iostream>
#include <list>
#include <vector>
#include "Mountains.hpp"


class World {
public:
	Shape* list[3];
	// std::list<Shape*> ObjectList;
	// std::vector<Shape*>* ObjectVector;

	World();
	~World();
	void draw_world(); // draw all objects in the world
};

#endif
