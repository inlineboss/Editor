#include "figure.h"
#include "painter.h"
#include "editor.h"
#include "canvas.h"

int main(){

	Editor editor(std::make_unique <Simple_canvas> ("SimpleCanvas"),
				  std::make_unique <Simple_painter> ("SimplePainter"));

	Figure& line = editor.new_figure(Figure_ID::line);
	Figure& square = editor.new_figure(Figure_ID::square);
	Figure& triangle = editor.new_figure(Figure_ID::triangle);

	editor.draw(square);
	editor.draw(triangle);
	editor.draw(line);

	editor.remove(square);
	editor.remove(triangle);
	editor.remove(line);

	editor.export_canvas("/dev/null");
	editor.import_canvas("/dev/null");

	editor.new_canvas<Simple_canvas>("NewSimpleCanvas");

	return 0;
}
