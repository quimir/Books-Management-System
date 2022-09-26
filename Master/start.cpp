#include "show.h"
int main()
{
    System *_start = new System;
    SystemAdd *_add = new SystemAdd;
    SystemShow *_show = new SystemShow;
    _start->alterNumber(0);
    _start->alterNumberDouble(0);
    _add->readFileBook();
    _add->readFilePeriodical();
    _show->choose(_start, _add);
    delete _start, _add, _show;
    _start = nullptr, _add = nullptr, _show = nullptr;
    return 0;
}