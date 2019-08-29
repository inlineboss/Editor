#ifndef PAINTER_INTERFACE_H_
#define PAINTER_INTERFACE_H_
#include "functional_interface.h"
#include "canvas_interface.h"

class Painter_interface: public Name_interface{
public:
	virtual void draw (Draw_interface& object, Canvas_interface& canvas) = 0;
	virtual void remove (Remove_interface& object, Canvas_interface& canvas) = 0;
	virtual ~Painter_interface(){};
};



#endif /* PAINTER_INTERFACE_H_ */
