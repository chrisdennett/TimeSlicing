#pragma once

#include "ofMain.h"

// This openFrameworks example is designed to demonstrate how to access the webcam
// Updated with code from here to make a slitscan
// http://formandcode.com/code-examples/transform-slit-scan

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        ofVideoGrabber webcam;

        int camWidth;
        int camHeight;
};
