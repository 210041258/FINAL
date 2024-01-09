#ifndef ADMIN_H
#define ADMIN_H
#include <unistd.h>
#include <windows.h>
#include <unistd.h>
#define wait_and_cleen sleep(3); system("cls");
#include "../user.h"
#include "../../employee/employee.h"
#include "../../tickets/tickets.h"


class admin : public user, public tickets , public employee
{
public:
    admin(string _username, string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_);
    ~admin();
    void admin_dashboard();
    void block_user();
    void add_ticket();
    void edit_ticket();
    void delete_ticket();
    void view_info_ticket();
    void track_op_user();
    void gui_1();
    void view_info_user();
};

#endif // ADMIN_H
