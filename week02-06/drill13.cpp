// g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

Rectangle makeRectangle(int x, int y, Color fillColour = Color::invisible, Color lineColour = Color::black)
{
	Rectangle r(Point{x,y}, 100, 100);
	r.set_fill_color(fillColour);
	r.set_color(lineColour);
	return r;
}

int main()
{
	int xmax = 800;
	int ymax = 1000;

	Simple_window win {Point{100,100}, xmax, ymax, "My window"};

	Lines grid;
	for (int x=100; x<xmax;x+=100)
		grid.add(Point{x,0},Point{x,ymax-200});
	for (int y =100; y<ymax-200; y+=100)
		grid.add(Point{0,y},Point{xmax,y});
	
	vector<Rectangle> v_rectangles;
	for (double i=0; i<800; i+=100)
		v_rectangles.push_back(makeRectangle(i, i, Color::red, Color::invisible));
	for (int i=0; i<v_rectangles.size(); ++i)
		win.attach(v_rectangles[i]);

	Image i1 (Point{0,200},"200x200.gif");
	Image i2 (Point{400,0},"200x200.gif");
	Image i3 (Point{200,600},"200x200.gif");


	win.attach(i1);
	win.attach(i2);
	win.attach(i3);
	win.attach(grid);
	win.wait_for_button();
	
	Image i4 (Point{0,0},"100x100.jpeg");
	win.attach(i4);
	win.wait_for_button();
	for (int i=0; i<8; ++i) {
		for (int j=0; j<8; ++j){
			i4.move(100,0);
			win.wait_for_button();
		}
		i4.move(-700,100);
		win.wait_for_button();
	}
	
}