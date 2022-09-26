#include "start.h"
#include "show.h"
int System::readNumber() const { return _number; }
int System::readNumberDouble() const { return _numberDouble; }
void System::alterNumber(int number) { this->_number = number; }
void System::alterNumberDouble(int number) { this->_numberDouble = number; }