#ifndef HOST_H
#define HOST_H
#include "../employee.h"
class host : public employee{
public:
host(int _Id,std::string _name,std::string _DoJ);
    void show_my_duty();
    void home_screen();
    void gui_1();
};
#endif
