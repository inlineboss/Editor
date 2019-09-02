#ifndef FIGURE_H_
#define FIGURE_H_

#include <iostream>
#include "figure_interface.h"
#include "functional_interface.h"

#include <memory>

enum class Figure_ID {
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

std::unique_ptr<Figure> create(Figure_ID id){
	switch(id){
	case Figure_ID::line: return std::make_unique<>();
	}
}


#endif /* FIGURE_H_ */
