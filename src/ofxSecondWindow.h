#pragma once

#include "ofMain.h"
#include <GLFW/glfw3.h>

class ofxSecondWindow {
    
public:
    void setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated);
    void begin();
    void end();
    int getWidth() { return width; }
    int getHeight() { return height; }
    
private:
    GLFWwindow *mainWindow, *auxWindow;
    int width, height;
};