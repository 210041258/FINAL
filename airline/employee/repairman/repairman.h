#ifndef REPAIRMAN_H
#define REPAIRMAN_H
#include "../employee.h"

class repairman : public employee{
public:
repairman(int _Id,std::string _name,std::string _DoJ);
void show_my_duty();
void home_screen();
void gui_1();
};
#endif
