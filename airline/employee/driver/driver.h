#ifndef DRIVER_H
#define DRIVER_H
#include "../employee.h"

class driver : public employee{
public:
driver(int _Id,std::string _name,std::string _DoJ);
void show_my_duty();
void home_screen();
void gui_1();
};
#endif
