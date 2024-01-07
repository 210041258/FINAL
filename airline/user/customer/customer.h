// customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../user.h"
#include "../../tickets/tickets.h" // Include the tickets header

class customer : public user {
public:
    customer(std::string _username, std::string _password, int _access, int _admin_access, int _co_cert_, int _visa_cert_, int _balance_);
    virtual ~customer();

    void customer_dashboard();
    void buy_ticket();
    void return_ticket();
    void gui_1();
    void view_tickets(); // Add this function declaration
    void view_my_information();
};

#endif // CUSTOMER_H
