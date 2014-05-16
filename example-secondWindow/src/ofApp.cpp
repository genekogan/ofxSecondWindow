#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("first window");

    // the arguments for the second window are its initial x and y position,
    // and its width and height. the width and height should match the fbo.
    // the last argument is whether the window should be undecorated, i.e. title bar
    // is visible. setting it to true removes the title bar.

    secondWindow.setup("second window", 50, 50, 1024, 768, false);

    // running the command below positions an undecorated window to display on a second
    // monitor or projector. this is a good way to set up a fullscreen display, while
    // retaining a control window in the primary monitor.
    
    //secondWindow.setup("second window", ofGetScreenWidth(), 0, fbo.getWidth(), fbo.getHeight(), true);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw to the main window
    ofSetColor(0, 255, 0);
    ofDrawBitmapString("this is the first window", 100, 100);
    ofRect(150, 190, 240, 160);
        
    // draw the second window
    secondWindow.begin();
    ofBackground(255);
    ofSetColor(0, 0, 255);
    ofDrawBitmapString("this is the second window", 100, 100);
    ofEllipse(320, 250, 200, 200);
    secondWindow.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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