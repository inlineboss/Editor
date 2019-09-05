#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>
#include "functional_interface.h"

#include <memory>

enum class Figure_ID : std::size_t {
	square,
	triangle,
	line,
};
/**
 * \brief Интерфейс фигуры
 */
class Figure: public Draw_interface,
						public Remove_interface{
public:
	static std::unique_ptr<Figure> create(Figure_ID id);
	virtual ~Figure(){};
};

/**
 * Класс квадрата
 */
class Square: public Figure{
public:
	virtual void draw () override{
		std::cout << "Square ";
	}
	virtual void remove () override{
		std::cout << "Square ";
	}
};

/**
 * Класс треугольника
 */
class Triangle: public Figure{
public:
	virtual void draw () override{
		std::cout << "Triangle ";
	}
	virtual void remove () override{
		std::cout << "Triangle ";
	}
};

/**
 * Класс линии
 */
class Line: public Figure{
public:
	virtual void draw () override{
		std::cout << "Line ";
	}
	virtual void remove () override{
		std::cout << "Line ";
	}
};

std::unique_ptr<Figure> Figure::create(Figure_ID id){

	switch(id){
		case Figure_ID::square: return std::make_unique<Square>();
			break;
		case Figure_ID::triangle: return std::make_unique<Triangle>();
			break;

		default: break;
	};

	return std::make_unique<Line>();
}


#endif /* FIGURE_H_ */
