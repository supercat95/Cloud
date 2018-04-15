#pragma once

#include "ofMain.h"
#include <list>
#include <vector>

using std::list;
using std::vector;

class ofApp : public ofBaseApp{

    ofPoint p;
    list<ofPoint> coordinates;
    vector<int> r, g, b, degree, x, y, z;
    int triangles = int(ofRandom(8000,10000)), rad = 1, sphereRadius = 300, alpha = 255;
    float sphereRotation = 0.0, speed = .1, triSize = ofRandom(5.0,10.0);
    
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
