# ofxSecondWindow 


## [Deprecated] openFrameworks now supports multiple windows as of release 0.9. Thus this addon is unnecessary, and will no longer be maintained. See examples/events/multiWindowExample to see how to create multiple windows in OF.


### About

This is a simple [openFrameworks](http://www.openframeworks.cc) addon which allows for creating multiple windows. It is based on the [discussion here](http://forum.openframeworks.cc/t/multiple-windows-using-glfw/12947/12) and [Daniel Almeida's code](https://github.com/danielfilipealmeida/MultiWindow).


### Obsolete?

As of openFrameworks release 0.9 (upcoming) and currently in the master branch, multiple windows is now supported in the core, making this addon probably unnecessary, though it continues to work, so consider it deprecated.


### Usage

A new window is initialized:

	secondWindow.setup(name, x, y, width, height, undecorated);
	
where name is the name of the window, x and y are the initial position, and width and height are the size of the second window.

undecorated is a bool -- if true, the second window has its title bar hidden (undecorated). you can use this to create a presentation window, e.g. in a second monitor or projector, i.e.

	secondWindow.setup("presentation window", ofGetScreenWidth(), 0, width, height, true);
	
where width and height refer to the resolution of the second monitor / projector.

To draw to it, encapsulate all drawing commands between a begin() and end() block, e.g.

	secondWindow.begin();
	// draw to second window here
	secondWindow.end();
	
You can make as many instances of ofxSecondWindow as you want to support multiple windows.

Note, you can also toggle their visibility.

	secondWindow.show();
	secondWindow.hide();
	secondWindow.toggleHidden();