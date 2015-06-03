#include "ofxSecondWindow.h"

ofxSecondWindow::ofxSecondWindow():mainWindow(NULL),auxWindow(NULL),bInited(false){}

ofxSecondWindow::~ofxSecondWindow() {
	bInited = false;
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);
    glfwDestroyWindow(auxWindow);
    auxWindow = NULL;
}
void ofxSecondWindow::setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated) {
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
    if (bInited) {
        glfwMakeContextCurrent(auxWindow);
        int width, height;
        glfwGetFramebufferSize(auxWindow, &width, &height);
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

void ofxSecondWindow::end(){
    if (bInited) {
        glfwSwapBuffers(auxWindow);
        glfwPollEvents();
        glfwMakeContextCurrent(mainWindow);
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

void ofxSecondWindow::show(){
    if (bInited) {
        glfwShowWindow(auxWindow);
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

void ofxSecondWindow::hide(){
    if (bInited) {
        glfwHideWindow(auxWindow);
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

void ofxSecondWindow::close(){
    bInited = false;
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);
    glfwDestroyWindow(auxWindow);
    auxWindow = NULL;
}

void ofxSecondWindow::setSize(int newWidth, int newHeight){
    if (bInited) {
        if (newWidth >= 0 && newHeight >= 0) {
            // Little hack since at resize, Y grows up and not down like oF standard
            int yDelta = newHeight - getHeight();
            setPosition(getPositionX(), getPositionY() + yDelta);
            
            glfwSetWindowSize(auxWindow, newWidth, newHeight);
        } else {
            throw std::invalid_argument("SecondWindow : windows should not be resized with negative values.");
        }
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

void ofxSecondWindow::setPosition(int newXPos, int newYPos){
    if (bInited) {
        glfwSetWindowPos(auxWindow, newXPos, newYPos);
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

int ofxSecondWindow::getWidth(){
    if (bInited) {
        int width, height;
        glfwGetWindowSize(auxWindow, &width, &height);
        return width;
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

int ofxSecondWindow::getHeight(){
    if (bInited) {
        int width, height;
        glfwGetWindowSize(auxWindow, &width, &height);
        return height;
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

int ofxSecondWindow::getPositionX(){
    if (bInited) {
        int xPos, yPos;
        glfwGetWindowPos(auxWindow, &xPos, &yPos);
        return xPos;
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

int ofxSecondWindow::getPositionY(){
    if (bInited) {
        int xPos, yPos;
        glfwGetWindowPos(auxWindow, &xPos, &yPos);
        return yPos;
    } else {
        throw std::invalid_argument("SecondWindow : window was not inited, or has been closed.");
    }
}

bool ofxSecondWindow::isInited(){
    return bInited;
}
