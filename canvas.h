#ifndef CANVAS_H_
#define CANVAS_H_
#include <iostream>

#include "canvas_interface.h"

class Simple_canvas: public Canvas_interface{
public:
	Simple_canvas(const char *name): name(name){}

	virtual void draw () override{
		std::cout << "create" << std::endl;
	}
	virtual void remove () override{
		std::cout << "delete" << std::endl;
	}

	virtual std::string title() override{
		return {name};
	}

private:
	const char * name;
};

#endif /* CANVAS_H_ */
