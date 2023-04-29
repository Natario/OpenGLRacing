// This file is part of CGLib project template.
//
// CGLib is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// CGLib is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CGLib; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// Copyright 2010 IST & J M Brisson Lopes


#include "MyApp.h"

namespace tutorial {

	MyApp::MyApp() : cg::Application("config.ini") {
		_window.caption = "CGLib Template";
		_window.width = 800;
		_window.height = 600;
	}
	MyApp::~MyApp() {
	}
	void MyApp::createEntities() {
		addEntity(new MyCamera());
		addEntity(new MyBox("Box1"));
		addEntity(new MyBat("Bat"));
	}
}
