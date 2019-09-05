#include "figure.h"
#include "painter.h"
#include "editor.h"
#include "canvas.h"

int main(){

	auto square = Figure::create(Figure_ID::square);
	auto triangle = Figure::create(Figure_ID::triangle);
	auto line = Figure::create(Figure_ID::line);

	Editor editor(std::make_unique <Simple_canvas> ("SimpleCanvas"),
				  std::make_unique <Simple_painter> ("SimplePainter"));

	editor.draw(*square);
	editor.draw(*triangle);
	editor.draw(*line);

	editor.remove(*square);
	editor.remove(*triangle);
	editor.remove(*line);

	editor.export_canvas("/dev/null");
	editor.import_canvas("/dev/null");

	editor.new_canvas<Simple_canvas>("NewSimpleCanvas");

	return 0;
}
