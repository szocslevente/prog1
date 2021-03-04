// g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;

	int xmax = 600;
	int ymax = 400;

	int x_orig = xmax/2;
    int y_orig = ymax/2;

    int xlength = xmax - 80; 
	int ylength = ymax - 80;

	int xscale = 30, yscale = 30; 

	Simple_window win {Point{100,100}, xmax, ymax, "My window"};

	Axis xa {Axis::x, Point{20, 350}, xlength, xlength/xscale, "x"};
	Axis ya {Axis::y, Point{20, 350}, ylength, ylength/yscale, "y"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::red);

	Function sine {sin,0,100,Point{20,200},3000,100,100};

	Polygon poly;
	poly.add(Point{350,300});
	poly.add(Point{350,100});
	poly.add(Point{500,300}); 
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	Rectangle r {Point{200,200}, 100, 50};

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});

	Text t {Point{150,150}, "Ez itt egy szoveg"};

	Image ii {Point{10,10},"badge.jpg"};
	
	win.wait_for_button();

	win.set_label("x tengely");
	win.attach(xa);
	
	win.wait_for_button();
	win.attach(ya);
	win.set_label("y tengely");

	win.wait_for_button();
	win.attach(sine);
	win.set_label("sinus");

	win.wait_for_button();
	win.attach(poly);
	win.set_label("poly");

	win.wait_for_button();
	win.attach(r);
	win.set_label("negyzet");
 
	win.wait_for_button();
	win.attach(poly_rect);
	win.set_label("negyzet 2");

	win.wait_for_button();
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	win.set_label("negyzet 3");

	win.wait_for_button();
	r.set_fill_color(Color::red);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("szines");

	win.wait_for_button();
	win.attach(t);
	win.set_label("text");

	win.wait_for_button();
	win.attach(ii);
	win.set_label("image");

	win.wait_for_button();
	
}
