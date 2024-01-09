#ifndef TICKETS_H
#define TICKETS_H
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class tickets
{
public:
    tickets(int _id, string _from, string _where, string _date_go, string _date_ret, int _price, int _t_visa_req, int _t_cov_req);
    tickets();
    virtual ~tickets();

    // Accessors
    int give_access_id();
    string give_access_from();
    string give_access_where();
    string give_access_date_go();
    string give_access_date_ret();
    int give_access_price();
    int give_access_t_visa_req();
    int give_access_t_cov_req();

    // Mutators
    void edit_access_id(int _id);
    void edit_access_from(string str);
    void edit_access_where(string where_);
    void edit_access_date_go(string go_);
    void edit_access_date_ret(string return_);
    void edit_access_price(int price_);
    void edit_access_t_visa_req(int visa_);
    void edit_access_t_cov_req(int cov_);

    // Functions
    int search_id(int id_);
    int save_ticket_direct();
    tickets extract_info_id(int id_);
    int delete_ticket(int id_);
    int print_info_id(int id_);

    // Sorting
    void sort_tickets();

private:
    int id;
    string from;
    string where;
    string date_go;
    string date_ret;
    int price;
    int t_visa_req;
    int t_cov_req;
};

#endif // TICKETS_H
