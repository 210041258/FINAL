#ifndef ADMIN_H
#define ADMIN_H

#include "../user.h"
#include "../../tickets/tickets.h"


class admin : public user, public tickets
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
