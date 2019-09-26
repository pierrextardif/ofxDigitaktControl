#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    ofSetVerticalSync(true);
    ofBackground(255);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetWindowTitle("Digitakt Midi Control");
    
    digitakt.setup();
    
}


//--------------------------------------------------------------
void ofApp::update() {
    digitakt.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0);
    digitakt.draw();
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    // clean up
    digitakt.exit();
}
