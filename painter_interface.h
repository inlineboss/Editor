#ifndef PAINTER_INTERFACE_H_
#define PAINTER_INTERFACE_H_
#include "functional_interface.h"
#include "canvas_interface.h"

/**
 * \brief Сущность рисования
 */
class Painter_interface: public Name_interface{
public:
	/**
	 * \brief Метод отрисовки
	 *
	 * \param object - Отрисовываемый объект
	 * \param canvas - Полотно для отрисовки
	 */
	virtual void draw (Draw_interface& object, Canvas_interface& canvas) = 0;

	/**
	 * \brief Метод стирания
	 *
	 * \param object - Отрисовываемый объект
	 * \param canvas - Полотно для отрисовки
	 */
	virtual void remove (Remove_interface& object, Canvas_interface& canvas) = 0;

	virtual ~Painter_interface(){};
};



#endif /* PAINTER_INTERFACE_H_ */
