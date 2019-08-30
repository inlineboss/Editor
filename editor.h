#ifndef EDITOR_H_
#define EDITOR_H_

#include <memory>

#include "canvas_interface.h"
#include "painter_interface.h"
#include "functional_interface.h"

/*
 * \brief Редактор
 */
class Editor{
public:
	Editor(Canvas_interface * canvas, Painter_interface* painter):
		canvas(canvas), painter(painter) {}
	/**
	 * \brief Отрисовка
	 */
	virtual void draw(Draw_interface& object){
		painter->draw(object, *canvas);
	}

	/**
	 * \brief Очищение
	 *
	 * \param object - Удаляемый объект
	 */
	virtual void remove(Remove_interface& object){
		painter->remove(object, *canvas);
	}

	/**
	 * \brief Экспорт полотна
	 *
	 * \param path_from - Путь сохранения файла
	 */
	virtual void export_canvas(const char *path_from){
		std::cout << "export canvas: "
				  << canvas->is_name()
				  << " -> "
				  << path_from
				  << std::endl;
	}

	/**
	 * \brief Импорт полотна
	 *
	 * \param path_where - путь до файла
	 */
	virtual void import_canvas(const char *path_where){
		std::cout << "import canvas: "
				  << canvas->is_name()
				  << " <- "
				  << path_where
				  << std::endl;
	}

	/**
	 * \brief Импорт полотна
	 *
	 * \param args - набор параметро для конструирования объекта
	 */
	template<typename Type, typename... Args>
	Type* new_canvas(Args... args){
			auto ptr = new Type(std::forward<Args...>(args...));
		std::cout << "create canvas : "
				  << ptr->is_name() << std::endl;
		return ptr;
	}


	std::unique_ptr<Canvas_interface> canvas;
	std::unique_ptr<Painter_interface> painter;

	virtual ~Editor(){};
};



#endif /* EDITOR_H_ */
