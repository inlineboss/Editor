#ifndef PAINTER_H_
#define PAINTER_H_
#include <iostream>

#include "painter_interface.h"

class Simple_painter: public Painter_interface{
public:

	Simple_painter(const char* name): name(name){};

	virtual void draw (Draw_interface& object, Canvas_interface& canvas) override{
		std::cout << name <<"| " << canvas.is_name() << "| draw -> ";
		object.draw();
		canvas.draw();
	}
	virtual void remove (Remove_interface& object, Canvas_interface& canvas) override{
		std::cout << name <<"| " << canvas.is_name() << "| remove -> ";
		object.remove();
		canvas.remove();
	}

	virtual std::string is_name() override{
		return {name};
	}

private:
	const char * name;
};



#endif /* PAINTER_H_ */
