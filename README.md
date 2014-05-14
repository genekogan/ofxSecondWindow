# ofxSecondWindow 

This is a simple [openFrameworks](http://www.openframeworks.cc) addon which allows for creating multiple windows. It is based on the [discussion here](http://forum.openframeworks.cc/t/multiple-windows-using-glfw/12947/12) and [Daniel Almeida's code](https://github.com/danielfilipealmeida/MultiWindow).

## Usage

A new window is initialized:

	secondWindow.setup(name, x, y, width, height, undecorated);
	
where name is the name of the window, x and y are the initial position, and width and height are the size of the second window.

undecorated is a bool -- if true, the second window has its title bar hidden (undecorated). you can use this to create a presentation window, e.g. in a second monitor or projector, i.e.

	secondWindow.setup("presentation window", ofGetScreenWidth(), 0, width, height, true);
	
where width and height refer to the resolution of the second monitor / projector.

To draw to it, draw first to an ofFbo, and then pass its pointer to secondWindow.

	secondWindow.draw(&fbo);
	
You can make as many instances of ofxSecondWindow as you want to support multiple windows.