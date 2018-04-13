#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackgroundGradient(0, 255);
    
    for (int i = 0; i < triangles; i++)
    {
        ofPoint p(ofRandom(-1,1), ofRandom(-1,1), ofRandom(-1,1));
        p.normalize(); // centers points into a sphere
        p *= sphereRadius;
        coordinates.push_back(p);
        
        ofEnableDepthTest(); // Adds depth to look more 3D
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    sphereRotation += speed;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateY(sphereRotation);
    
    for (ofPoint point: coordinates)
    {
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        ofRotate(ofRandom(0,10), ofRandom(0,10), ofRandom(0,10), ofRandom(0,10));
        
        ofSetCircleResolution(3);
        ofDrawCircle(point, triSize);
        
//        ofDrawTriangle(point, point + 1, point +2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_UP)
    {
        triSize++;
    }
    
    if (key == OF_KEY_DOWN)
    {
        triSize--;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    key == 'G';
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    if (x > ofGetWidth()/2)
    {
        sphereRotation++;
    } else
    {
        sphereRotation--;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    sphereRotation = 0;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
