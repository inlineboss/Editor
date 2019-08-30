#ifndef FIGURE_INTERFACE_H_
#define FIGURE_INTERFACE_H_

#include "functional_interface.h"

/**
 * \brief Интерфейс фигуры
 */
class Figure_interface: public Draw_interface,
						public Remove_interface{
public:
	virtual ~Figure_interface(){};
};

#endif /* FIGURE_INTERFACE_H_ */
