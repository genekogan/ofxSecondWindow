#pragma once

#include "ofMain.h"
#include <GLFW/glfw3.h>

class ofxSecondWindow {
    
public:
    void setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated);
    void draw(ofFbo *fbo);

private:
    GLFWwindow *mainWindow, *auxWindow;
};