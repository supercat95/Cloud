#pragma once

#include "ofMain.h"
#include <vector>

using std::vector;

class ofApp : public ofBaseApp{

    vector<ofPoint> coordinates;
    int triangles = int(ofRandom(500,1000));
    float sphereRadius = 300, sphereRotation = 0, speed = .1, triSize = ofRandom(5,10);
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
