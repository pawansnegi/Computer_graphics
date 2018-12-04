This assignment has been done by 

pawan Singh Negi 

We declare that this assignment has been done by our own ideas
and has not been copied from some where else. Any code snippet
which has been referenced has been properly cited below.

[1] https://stackoverflow.com/questions/37194845/using-glfw-to-capture-mouse-dragging-c

last visited on August 14 2018 

[2] https://en.wikipedia.org/wiki/Flood_fill

last visited on August 14 2018 

[3] have taken function drawline in primitive.cpp 
    from 
    line2 in bressenham.cpp given by Instructor

=================
Task

To Do :
The class point_brush_t implements a point brush, i.e., a brush that colors a separate point with each click. A brush for point size 1 is already implemented. Extend the stroke function to support other point sizes. For e.g., a size 4 point brush, could color 4x4 pixels at a time or all pixels within a circle of radius 4. 

Similarly, the class eraser_point_brush_t implements another point brush that draws with the background color and works as an eraser. Extend the stroke function in this class to implement the eraser for different brush sizes. 

Add another brush class smooth_brush_t that implements a smooth brush by creating a smooth curve of pixels between each successive mouse click. This is like a pencil tool in photoshop or gimp. The width of the curve is governed by the size of the brush. 

Currently the only primitive mode that is implemented is a point. This allows free hand drawing. Add a line mode where every two successive clicks create a straight line segment, with the current brush thickness. Add a triangle strip mode where the first 3 clicks adds a triangle, and thereafter every click adds an additional triangle. These are to be added to the primitive.cpp and primitive.hpp file. 

Add the P/p key to keyboard callback to cycle the primitive mode, and make sure the brushes - both drawing and erasing, behave appropriately depending on the primitive mode. Print a message to the console every time the mode cycles with the name of the current mode. The implementation for the keyboard callback can be found in the file gl_framework.cpp. 

Implement floodfill in fill.cpp/fill.hpp. Floodfill should fill all pixels contiguously connected to a clicked seed pixel, till it hits a pixel that is of a different color from the seed pixel or the canvas boundary. 

Add the F/f key to select the fill tool. 

Add the B/b key to select the brush tool. 

Add the E/e key to select the eraser tool. 

Add the C/c key to select the current drawing color. The color can be input on the console. mydraw expects colors in RGBA, with each channel ranging from 0.0 to 1.0. For opaque colors, the A channel can default to 1.0. 

Add the D/d key to select the current background color. Note this only changes the color of the eraser and not of the entire canvas. 

Create one drawing using your mydraw implementation of any indoor/outdoor scene. Make sure the drawing shows off the use of various features that your implementation supports. Save this drawing as submit.tga and add it to the folder called drawing in the repository. 

Write a pdf report explaining what you added to mydraw to implement the above mentioned features. Name this report file submit.pdf. Make sure you include the names of both members of your group in the report. Put the report in the doc folder in the mydraw tree. 
