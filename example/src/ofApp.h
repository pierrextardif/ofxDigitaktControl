#pragma once

#include "ofMain.h"

#include "ofxDigitaktControl.hpp"

class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();
	void exit();
	
    ofxDigitaktControl digitakt;
};
