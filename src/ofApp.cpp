#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    for (int i = 0; i < triangles; i++)
    {
        p.set(ofRandom(-1 * rad, rad), ofRandom(-1 * rad, rad), ofRandom(-1 * rad, rad));
        p.normalize(); // centers points into a sphere
        p *= sphereRadius;
        coordinates.push_back(p);
        
        ofEnableDepthTest(); // Adds depth to look more 3D
    }
    
    for (int i = 0; i < triangles; i++)
    {
        r.push_back(ofRandom(255)), g.push_back(ofRandom(255)), b.push_back(ofRandom(255));
        degree.push_back(ofRandom(0,10)), x.push_back(ofRandom(0,10)), y.push_back(ofRandom(0,10)), z.push_back(ofRandom(0,10));
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
    ofColor inside(255,125,75);
    ofColor outside(75,125,255);
    ofBackgroundGradient(inside, outside, OF_GRADIENT_CIRCULAR);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateY(sphereRotation);
    
//    for (ofPoint point: coordinates)
//    {
        for (int i = 0; i < triangles; i++)
        {
            ofSetColor(r[i], g[i], b[i]), alpha;
            ofRotate(degree[i], x[i], y[i], z[i]);
        
        ofSetCircleResolution(3);
        ofDrawCircle(p, triSize);
        
//        ofDrawTriangle(point, point + 1, point +2);
        // for loop i iterating through the vector
        // for loop j iterating through every 3
        // combine to make the 3 points to make a triangle
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_UP) // zoom in
    {
        triSize++;
        
        rad++;
        p+= rad;
    }
    
    if (key == OF_KEY_DOWN) // zoom out
    {
        triSize--;
        
        if (triSize < 1)
        {
            triSize = 1;
        }
        
        rad--;
        if (rad < 1)
        {
            rad = 1;
        } else
        {
            p-= rad;
        }
    }
    
    coordinates.push_back(p);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
//    key == 'G';
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    if (ofGetMouseX() > ofGetPreviousMouseX())
    {
        sphereRotation++;
        ofRotateY(sphereRotation);
    } else if (ofGetMouseX() < ofGetPreviousMouseX())
    {
        sphereRotation--;
        ofRotateY(sphereRotation);
    }
    
//    if (ofGetMouseY() > ofGetPreviousMouseY())
//    {
//        sphereRotation--;
//        ofRotateX(sphereRotation);
//    } else if (ofGetMouseY() < ofGetPreviousMouseY())
//    {
//        sphereRotation++;
//        ofRotateX(sphereRotation);
//    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

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
