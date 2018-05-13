#ifndef ABLAK_H_INCLUDED
#define ABLAK_H_INCLUDED

#include "widgetek.h"
#include <vector>

class Window {
protected:
    std::vector<Widget*>widgetek;
public:
    virtual void esemeny(std::string mitortent){}
    void event_loop();
};

#endif // ABLAK_H_INCLUDED
