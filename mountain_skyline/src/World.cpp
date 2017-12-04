/**
 * File: World.hpp
 */

#include "World.hpp"
World::World() {
	list[0] = new Base();
	list[1] = new House();
	list[2] = new Mountains();
	list[3] = new Clouds();
	list[4] = new Cylinder();
	list[5] = new Cone();

	//Mesh* mymesh = new Mesh();
	//mymesh->readMesh("barn.3VN");
	//mymesh->readMesh("BUCK.3VN");
	//list[1] = mymesh;

    /* object list
	ObjectList.push_back(list[0]);
	ObjectList.push_back(list[1]);
    */

	/* object vector
	ObjectVector = new std::vector<Shape*>(2);
	std::vector<Shape*>& ObjectVecotrRef = *ObjectVector;
	ObjectVectorRef[0] = list[0];
	ObjectVectorRef[1] = list[1];
    */
}

World::~World(){
    delete list[0];
	delete list[1];
	delete list[2];
	delete list[3];
	delete list[4];
	delete list[5];
}

void World::draw_world() {
	list[0]->draw();
	list[1]->draw();
	list[2]->draw();
	list[3]->draw();
	list[4]->draw();
	list[5]->draw();
	/*
	for (std::list<Shape*>::const_iterator it = ObjectList.begin(); it!=ObjectList.end(); ++it) {
		(*it)->draw();
	} */

	/*
	std::vector<Shape*>& ObjectVectorRef = *ObjectVector;
	for (int i = 0; i < 2; i++ ) {
		 ObjectVectorRef[i]->draw();
	} */

}

