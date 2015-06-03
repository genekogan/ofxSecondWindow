#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("First window (main)");

    // the arguments for the second window are its initial x and y position,
    // and its width and height. the last argument is whether the window
    // should be undecorated, i.e. title bar is visible. setting it to
    // true removes the title bar.

    secondWindow.setup("Second window", 200, 200, 1024, 768, false);

    // running the command below positions an undecorated window to display on a second
    // monitor or projector. this is a good way to set up a fullscreen display, while
    // retaining a control window in the primary monitor.
    
    //secondWindow.setup("second window", ofGetScreenWidth(), 0, 1280, 800, true);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw to the main window
	ofBackground(220);
    ofSetColor(0, 170, 0);
	ofRect(20, 20, 50, 40);
	ofSetColor(0);
    ofDrawBitmapString("This is the first window", 30, 80);
	ofDrawBitmapString("Press up, left, down and right to displace the second window", 30, 110);
	ofDrawBitmapString("Press + and - to resize it", 30, 140);
	ofDrawBitmapString("Press c to close and s to set it up back again (be carefull with these !) ", 30, 170);
        
    // draw the second window
	if (secondWindow.isInited()) {
		secondWindow.begin();
		ofBackground(220);
		ofSetColor(0, 0, 170);
		ofEllipse(50, 20, 60, 30);
		ofSetColor(0);
		ofDrawBitmapString("This is the second window", 30, 65);
		secondWindow.end();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
        case 'c':			// Close secondWindow
            secondWindow.close();
			draw();
            break;
		case 's':			// Re-setup secondWindow
			if (!secondWindow.isInited()) {
				secondWindow.setup("Second window", 200, 200, 1024, 768, false);
			}
			draw();
			break;
        case OF_KEY_UP:     // Move secondWindow up
			if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX(), secondWindow.getPositionY() - 20);
			}
            break;
        case OF_KEY_LEFT:   // Move secondWindow left
            if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX() - 20, secondWindow.getPositionY());
			}
            break;
        case OF_KEY_DOWN:   // Move secondWindow down
            if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX(), secondWindow.getPositionY() + 20);
			}
            break;
        case OF_KEY_RIGHT:  // Move secondWindow right
            if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX() + 20, secondWindow.getPositionY());
			}
            break;
        case '+':			// Widen secondWindow
			if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX() - 25, secondWindow.getPositionY() - 25);
				secondWindow.setSize(secondWindow.getWidth() + 50, secondWindow.getHeight() + 50);
			}
            break;
		case '-':			// Shrink secondWindow
			if (secondWindow.isInited()) {
				secondWindow.setPosition(secondWindow.getPositionX() + 25, secondWindow.getPositionY() + 25);
				secondWindow.setSize(secondWindow.getWidth() - 50, secondWindow.getHeight() - 50);
			}
			break;
        default:
            break;
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