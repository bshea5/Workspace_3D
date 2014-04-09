#include <vector>
#include <iostream>
#include "face.h"
#include "Display.h"
#include "algebra3.h"

void parser(const char* file, std::vector<Face*> *faces); // A function for loading faces from a file

class Controller{
	private:
		double rate = 0.5;
		double rotation = 10.0;
		vec3 axis = vec3(0, rate, 0);
		std::vector<Face*> faces;	// Store all of the faces/polygons in the scene
		int selected;				// Which face is currently selected
		Display* d;					// A pointer to the display mechanisms
	public:
		Controller(); 
		~Controller();

		const double getRate();				// Get the rate of rotation
		const int numPolys();				// Get the number of faces
		const mat4 getPoly(int i);			// Get a certain face
		void setPoly(mat4 m);				// set a face with new/edited vertices
		const int getSelected();			// Get which face has been selected
		void select(int i);					// Set the selected face
//		void extrudeSelected(float depth);	// Perform an extrusion
		//void cb_startb(void) { Fl::add_timeout(0.5, rotatingCB); }
		void Controller::rotate_cube();		// rotate cube

		static void callback(void* data);	// Callback to rotate cube

};