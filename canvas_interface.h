#ifndef CANVAS_INTERFACE_H_
#define CANVAS_INTERFACE_H_
#include <string>

#include "functional_interface.h"

class Canvas_interface: public Draw_interface,
						public Remove_interface,
						public Title_interface{
public:
	virtual ~Canvas_interface(){};
};



#endif /* CANVAS_INTERFACE_H_ */
