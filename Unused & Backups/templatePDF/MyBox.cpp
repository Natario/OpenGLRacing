#include "MyBox.h"

#include <iostream>

namespace tutorial {

	MyBox::MyBox(std::string id) : cg::Entity(id) {
	}
	MyBox::~MyBox(){
	}

	// Generate a random number
	double MyBox::randomBetween(double min, double max) {
		return fmod( rand(), ((max-min)+1)) + min;
	}

	void MyBox::init() {
		double min_size =
			cg::Properties::instance()->getDouble("MIN_SIZE");
		double max_size =
			cg::Properties::instance()->getDouble("MAX_SIZE");

		// Creates box
		_winWidth =
			cg::Manager::instance()->getApp()->getWindow().width;
		_winHeight =
			cg::Manager::instance()->getApp()->getWindow().height;
		_position =
			cg::Vector2d(randomBetween(0,_winWidth),randomBetween(0,_winHeight));
		_size =
			cg::Vector2d(randomBetween(min_size,max_size), randomBetween(min_size,max_size));
		_color =
			cg::Vector3d(randomBetween(0.1,0.9), randomBetween(0.1,0.9), randomBetween(0.1,0.9));
		_velocity =
			cg::Vector2d(randomBetween(100,300),randomBetween(100,300));
			
		_bat = (MyBat*)cg::Registry::instance()->get("Bat");



			
		std::ofstream& file =
			cg::DebugFile::instance()->getOutputFileStream();
		file << "Created a box with size " << _size << "." << std::endl;
	}
	
	void MyBox::draw() {
		cg::Vector2d min = _position -_size/2.0;
		cg::Vector2d max = _position + _size/2.0;
		glColor3dv(_color.get());
		glLineWidth(1.5);
		glBegin(GL_LINE_LOOP);
			glVertex3d(min[0],min[1], 0);
			glVertex3d(max[0],min[1], 0);
			glVertex3d(max[0],max[1], 0);
			glVertex3d(min[0],max[1], 0);
		glEnd();
	}

	void MyBox::update(unsigned long elapsed_millis) {
	
		double elapsed_seconds = elapsed_millis / 1000.0;
		_position += _velocity * elapsed_seconds;
		
		if(_position[0] < 0) {
			_position[0] = 0;
			_velocity[0] = -_velocity[0]; }
		if(_position[0] > _winWidth) {
			_position[0] = _winWidth;
			_velocity[0] = -_velocity[0]; }
		if(_position[1] < 0) {
			_position[1] = 0;
			_velocity[1] = -_velocity[1]; }
		if(_position[1] > _winHeight) {
			_position[1] = _winHeight;
			_velocity[1] = -_velocity[1]; }
			
		if(_bat->isCollision(_position, _size)) {
			_velocity[1] = -_velocity[1]; }

	}


}
