#include "figure.h"
#include "painter.h"
#include "editor.h"
#include "canvas.h"

int main(){
	Square square;
	Triangle triangle;
	Line line;
	Editor editor(new Simple_canvas("SimpleCanvas"),
				  new Simple_painter("SimplePainter"));

	editor.draw(square);
	editor.draw(triangle);
	editor.draw(line);

	editor.remove(square);
	editor.remove(triangle);
	editor.remove(line);

	editor.export_canvas("/dev/null");
	editor.import_canvas("/dev/null");

	return 0;
}
