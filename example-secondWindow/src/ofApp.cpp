#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("first window");

    // the arguments for the second window are its initial x and y position,
    // and its width and height. the last argument is whether the window
    // should be undecorated, i.e. title bar is visible. setting it to
    // true removes the title bar.

    secondWindow.setup("second window", 50, 50, 1024, 768, false);

    // running the command below positions an undecorated window to display on a second
    // monitor or projector. this is a good way to set up a fullscreen display, while
    // retaining a control window in the primary monitor.
    
    //secondWindow.setup("second window", ofGetScreenWidth(), 0, 1280, 800, true);
    
    // click 's' to toggle visibility of second window
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw to the main window
    ofSetColor(0, 255, 0);
    ofDrawBitmapString("this is the\nfirst window", 30, 80);
    ofRect(20, 20, 50, 40);
        
    // draw the second window
    secondWindow.begin();
    ofBackground(255);
    ofSetColor(0, 0, 255);
    ofDrawBitmapString("this is the\nsecond window", 30, 65);
    ofEllipse(20, 20, 60, 30);
    secondWindow.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='s') {
        secondWindow.toggleHidden();
    }
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