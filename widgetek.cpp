#include "widgetek.h"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int a, int b, int c, int d) : _helyx(a), _helyy(b), _meretx(c), _merety(d){
}

bool Widget::kivalasztott(int eger_x, int eger_y){
 return eger_x>_helyx && eger_x<_helyx+_meretx && eger_y>_helyy && eger_y<_helyy+_merety;
}
