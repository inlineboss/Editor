#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>
#include "figure_interface.h"

class Square: public Figure_interface{
public:
	virtual void draw () override{
		std::cout << "Square ";
	}
	virtual void remove () override{
		std::cout << "Square ";
	}
};

class Triangle: public Figure_interface{
public:
	virtual void draw () override{
		std::cout << "Triangle ";
	}
	virtual void remove () override{
		std::cout << "Triangle ";
	}
};

class Line: public Figure_interface{
public:
	virtual void draw () override{
		std::cout << "Line ";
	}
	virtual void remove () override{
		std::cout << "Line ";
	}
};



#endif /* FIGURE_H_ */
