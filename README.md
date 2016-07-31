# Paint
Paint-like application, allows to draw primitives and arbitrary paintings with mouse.
I used Qt framework for solving the given task. 
Tools: Qt 5.6.0, Qt Creator v. 3.61, MSVC 2015 64 bit.

Please make sure to use c++14 compatible compiler.
This application offers tools for drawing such geometric primitives: line, rectangle, circle. Also arbitrary drawing with the mouse is available. 
User is free to customise the pen: color is chosen from the palette and width can be set. The canvas supports undo and redo changes. 
Unfortunately, i was not able to run and test picture saving feature (in mainwindow.h you can find the description of the problem and the cause), 
however i implemented the example of the code that do this, and i really hope it's not error-prone :)

All drawable shapes are subclasses of Shape and IDrawable abstract classes. Application uses RTTI, so it is possible to add more 
drawable classes, - just:
 
- inherit IDrawable superclass (dont forget to override IDrawable::draw and implement the logics of displaying figure);
- update dictionary DrawAssistant::_shapesList: add std::pair with new ShapeId and lambda, that creates your new class;
- you also have to add button on gui, provide passing new ShapeId to DrawAssistant for creating instance of new Shape.

DrawAssistant is a singleton, that helps to interact GUI and canvas. Also, the logic of retrieving shapes coordinates, 
current pen color and width are encapsulated there.
