#ifndef WIDGETEK_H_INCLUDED
#define WIDGETEK_H_INCLUDED

#include <string>
#include "graphics.hpp"

using namespace genv;

class Widget{
protected:
    int _helyx, _helyy, _meretx, _merety;
public:
    Widget(int a, int b, int c, int d);
    virtual bool kivalasztott(int eger_x, int eger_y);
    virtual void kirajzol() =0;
    virtual void akcio(event ev) =0;
    virtual std::string getter() =0;


};                                                                                                                                                                                                                                                          //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :);


#endif // WIDGETEK_H_INCLUDED
