#include "ofxSecondWindow.h"

ofxSecondWindow::ofxSecondWindow():mainWindow(NULL),auxWindow(NULL),bInited(false){
    glfwInit();
}

ofxSecondWindow::~ofxSecondWindow() {
    close();
}

void ofxSecondWindow::setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated) {
    if (bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwWindowHint(GLFW_DECORATED, !undecorated);
    mainWindow = glfwGetCurrentContext();
    auxWindow = glfwCreateWindow(width, height, name, NULL, mainWindow);    
    glfwSetWindowPos(auxWindow, xpos, ypos);
    
    /* enable alpha blending by default */
    glfwMakeContextCurrent(auxWindow);
    glEnable(GL_BLEND);
#ifndef TARGET_OPENGLES
    glBlendEquation(GL_FUNC_ADD);
#endif
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwMakeContextCurrent(mainWindow);
    bInited = true;
}

void ofxSecondWindow::begin(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwMakeContextCurrent(auxWindow);
    int width, height;
    glfwGetFramebufferSize(auxWindow, &width, &height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void ofxSecondWindow::end(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwSwapBuffers(auxWindow);
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);
}

void ofxSecondWindow::show(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwShowWindow(auxWindow);
}

void ofxSecondWindow::hide(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwHideWindow(auxWindow);
}

void ofxSecondWindow::close(){
    if (!bInited) { return; }
    bInited = false;
    glfwSwapBuffers(auxWindow);
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);
    glfwDestroyWindow(auxWindow);
}

void ofxSecondWindow::setSize(int newWidth, int newHeight, bool resizeCentered){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    if (newWidth >= 0 && newHeight >= 0) {
        
        int xDelta = newWidth - getWidth();
        int yDelta = newHeight - getHeight();
        
        if (resizeCentered) {
            setPosition(getPositionX() - (xDelta / 2), getPositionY() + (yDelta / 2));
        } else {
            // Little hack since at resize, Y grows up and not down like oF standard
            setPosition(getPositionX(), getPositionY() + yDelta);
        }
        glfwSetWindowSize(auxWindow, newWidth, newHeight);
        
    } else {
        ofLogError("ofxSecondWindow", "Window should not be resized with negative values.");
        return;
    }
}

void ofxSecondWindow::setPosition(int newXPos, int newYPos){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return;
    }
    glfwSetWindowPos(auxWindow, newXPos, newYPos);
}

int ofxSecondWindow::getWidth(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return 0;
    }
    int width, height;
    glfwGetWindowSize(auxWindow, &width, &height);
    return width;
}

int ofxSecondWindow::getHeight(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return 0;
    }
    int width, height;
    glfwGetWindowSize(auxWindow, &width, &height);
    return height;
}

int ofxSecondWindow::getPositionX(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return 0;
    }
    int xPos, yPos;
    glfwGetWindowPos(auxWindow, &xPos, &yPos);
    return xPos;
}

int ofxSecondWindow::getPositionY(){
    if (!bInited) {
        ofLogWarning("ofxSecondWindow", "Window was not inited, or has been closed.");
        return 0;
    }
    int xPos, yPos;
    glfwGetWindowPos(auxWindow, &xPos, &yPos);
    return yPos;
}

bool ofxSecondWindow::isInited(){
    return bInited;
}
