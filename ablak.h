#ifndef ABLAK_H_INCLUDED
#define ABLAK_H_INCLUDED

#include "widgetek.h"
#include <vector>

using namespace std;

class Window {
protected:
    vector<Widget*>widgetek;
public:
    void event_loop(const int XX, const int YY);
};

#endif // ABLAK_H_INCLUDED
