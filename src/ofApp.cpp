#include "ofApp.h"

int video_width = 1280;
int video_height = 960;
const int totalSlices = 80;
ofTexture frames[totalSlices];
int n;
int currentFrame = 0;
bool allSlicesSaved = false;
float sliceSize = video_height / totalSlices;

void ofApp::setup(){
	webcam.setup(video_width, video_height);
	webcam.setDesiredFrameRate(60);
}

void ofApp::update(){
    webcam.update();

	if (webcam.isFrameNew()) {
		for (n = totalSlices-1; n > 0; n--)
			frames[n] = frames[n - 1];
		frames[0].clear();
		frames[0].loadData(webcam.getPixels());
	}
}

void ofApp::draw(){
	float sliceY = 0;
	for (n = totalSlices - 1; n >= 0; n--) {
		frames[n].drawSubsection(0, sliceY, video_width, sliceSize, 0, sliceY);
		sliceY += sliceSize;
	}

	frames[0].drawSubsection(0, sliceY, video_width*1.2, sliceSize*1.2, 0, sliceY, video_width, sliceY);
}