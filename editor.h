#ifndef EDITOR_H_
#define EDITOR_H_

#include <memory>

#include "canvas_interface.h"
#include "painter_interface.h"
#include "functional_interface.h"

class Editor{
public:
	Editor(Canvas_interface * canvas, Painter_interface* painter):
		canvas(canvas), painter(painter) {}

	virtual void draw(Draw_interface& object){
		painter->draw(object, *canvas);
	}

	virtual void remove(Remove_interface& object){
		painter->remove(object, *canvas);
	}

	virtual void export_canvas(const char *path_from){
		std::cout << "export canvas: "
				  << canvas->is_name()
				  << " -> "
				  << path_from
				  << std::endl;
	}
	virtual void import_canvas(const char *path_where){
		std::cout << "import canvas: "
				  << canvas->is_name()
				  << " <- "
				  << path_where
				  << std::endl;
	}

	std::unique_ptr<Canvas_interface> canvas;
	std::unique_ptr<Painter_interface> painter;

	virtual ~Editor(){};
};



#endif /* EDITOR_H_ */
