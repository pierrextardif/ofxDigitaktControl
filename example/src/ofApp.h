#pragma once

#include "ofMain.h"

#include "ofxDigitaktControl.hpp"

class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();
    void keyPressed(int key);
	void exit();
	
    ofxDigitaktControl digitakt;
};
