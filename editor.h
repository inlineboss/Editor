#ifndef EDITOR_H_
#define EDITOR_H_

#include <memory>
#include <unordered_map>

#include "canvas_interface.h"
#include "painter_interface.h"
#include "functional_interface.h"
#include "figure.h"

/*
 * \brief Редактор
 */
class Editor{
public:
	Editor(std::unique_ptr<Canvas_interface> canvas, std::unique_ptr<Painter_interface> painter):
		canvas(std::move(canvas)), painter(std::move(painter)) {}
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
				  << canvas->title()
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
				  << canvas->title()
				  << " <- "
				  << path_where
				  << std::endl;
	}

	/**
	 * \brief Создание нового полотна
	 *
	 * \param args - Набор параметров для конструирования объекта
	 *
	 * \tparam Type - Тип объекта
	 * \tparam Args - Типы параметров
	 */
	template<typename Type, typename... Args>
	std::unique_ptr<Type> new_canvas(Args... args){
			auto ptr = std::make_unique<Type>(std::forward<Args...>(args...));
		std::cout << "create canvas : "
				  << ptr->title() << std::endl;
		return std::move(ptr);
	}

	Figure& new_figure(Figure_ID id){

		auto ptr = Figure::create(id);

		std::cout << "create figure " << std::endl;

		storage[++index_figure] = Figure::create(id);

		return *storage[index_figure];
	}

	std::unique_ptr<Canvas_interface> canvas;
	std::unique_ptr<Painter_interface> painter;

	std::unordered_map<std::size_t, std::unique_ptr<Figure>> storage;
	std::size_t index_figure{0};

	virtual ~Editor(){};
};



#endif /* EDITOR_H_ */
