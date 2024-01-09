#include "tickets.h"


using namespace std;

tickets::tickets(int _id, string _from, string _where, string _date_go, string _date_ret, int _price, int _t_visa_req, int _t_cov_req)
{
    id = _id;
    from = _from;
    where = _where;
    date_go = _date_go;
    date_ret = _date_ret;
    price = _price;
    t_visa_req = _t_visa_req;
    t_cov_req = _t_cov_req;
    if(!(search_id(_id)))
    {
        if(id != 0){
        save_ticket_direct();
        }
    }
}

tickets::~tickets() {}
tickets::tickets() {}

int tickets::give_access_id()
{
return id;
}

string tickets::give_access_from()
{
    return from;
}

string tickets::give_access_where()
{
    return where;
}

string tickets::give_access_date_go()
{
    return date_go;
}

string tickets::give_access_date_ret()
{
    return date_ret;
}

int tickets::give_access_price()
{
    return price;
}

int tickets::give_access_t_visa_req()
{
    return t_visa_req;
}

int tickets::give_access_t_cov_req()
{
    return t_cov_req;
}

void tickets::edit_access_id(int _id)
{
    if(id!=_id)
    {
        id = _id;
    }
}

void tickets::edit_access_from(string str)
{
    if(from!=str)
    {
        from = str;
    }
}

void tickets::edit_access_where(string where_)
{
    if(where!=where_)
    {
        where = where_;
    }
}

void tickets::edit_access_date_go(string go_)
{
    if(date_go!=go_)
    {
        date_go = go_;
    }
}

void tickets::edit_access_date_ret(string return_)
{
    if(date_ret!=return_)
    {
        date_ret = return_;
    }
}

void tickets::edit_access_price(int price_)
{
    if(price!=price_)
    {
        price = price_;
    }
}

void tickets::edit_access_t_visa_req(int visa_)
{
    if(visa_!=t_visa_req)
    {
        t_visa_req = visa_;
    }
}

void tickets::edit_access_t_cov_req(int cov_)
{
    if(cov_!=t_cov_req)
    {
        t_cov_req = cov_;
    }
}

int tickets::save_ticket_direct()
{
    ofstream finput("tickets.txt", ios::app);
    finput << give_access_id() << " " << give_access_from() << " ";
    finput << give_access_where() << " " << give_access_date_go() << " ";
    finput << give_access_date_ret() << " " << give_access_price() << " ";
    finput << give_access_t_visa_req() << " " << give_access_t_cov_req() << endl;
    finput.close();
    sort_tickets();
    return 1;
}

int tickets::search_id(int id_)
{
    int arr[4];
    string str[4];
    ifstream fileoutput("tickets.txt");
    while (fileoutput >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1] >> arr[2] >> arr[3])
    {
        if (id_ == arr[0])
        {
            fileoutput.close();
            return 1;
        }
    }
    fileoutput.close();
    return 0;
}

int tickets::print_info_id(int id_)
{
    int intarr[4];
    string strarr[4];
    ifstream fileoutput("tickets.txt");
    if (!(fileoutput.is_open()))
    {
        cerr << "Error: Unable to open file." << endl;
        return 0;
    }
    while (fileoutput >> intarr[0] >> strarr[0] >> strarr[1] >> strarr[2] >> strarr[3] >> intarr[1] >> intarr[2] >> intarr[3])
    {
        if (id_ == intarr[0])
        {
            cout << "Ticket Information: " << endl;
            cout << "The Ticket Id: " << intarr[0] << endl;
            cout << "The Ticket From: " << strarr[0] << endl;
            cout << "To: " << strarr[1] << endl;
            cout << "Date to start the flight: " << strarr[2] << endl;
            cout << "Date to return the flight: " << strarr[3] << endl;
            cout << "The price of flight: " << intarr[1] << endl;
            cout << "The Visa-Country requirement of flight: " << intarr[2] << endl;
            cout << "The Covid-19 requirement of flight: " << intarr[3] << endl;
            fileoutput.close();
            return 1;
        }
    }
    fileoutput.close();

    return 0;
}

tickets tickets::extract_info_id(int id_)
{
    tickets t(0, "", "", "", "", 0, 0, 0);
    int intarr[4];
    string strarr[4];
    ifstream fileoutput("tickets.txt");
    while (fileoutput >> intarr[0] >> strarr[0] >> strarr[1] >> strarr[2] >> strarr[3] >> intarr[1] >> intarr[2] >> intarr[3])
    {
        if (id_ == intarr[0])
        {
            t.edit_access_id(intarr[0]);
            t.edit_access_from(strarr[0]);
            t.edit_access_where(strarr[1]);
            t.edit_access_date_go(strarr[2]);
            t.edit_access_date_ret(strarr[3]);
            t.edit_access_price(intarr[1]);
            t.edit_access_t_visa_req(intarr[2]);
            t.edit_access_t_cov_req(intarr[3]);
            fileoutput.close();
            return t;
        }
    }
    fileoutput.close();
}

int tickets::delete_ticket(int id_)
{
    bool find = false;
    int arr[4];
    string str[4];
    ifstream fileoutput("tickets.txt");
    ofstream fileinput("tickets_new.txt");
    while (fileoutput >> arr[0] >> str[0] >> str[1] >> str[2] >> str[3] >> arr[1] >> arr[2] >> arr[3])
    {
        if (id_ != arr[0])
        {
            fileinput << arr[0] << " " << str[0] << " ";
            fileinput << str[1] << " " << str[2] << " ";
            fileinput << str[3] << " " << arr[1] << " ";
            fileinput << arr[2] << " " << arr[4] << endl;
        }
        if (id_ != arr[0])
        {
            find = true;
        }
    }
    fileoutput.close();
    fileinput.close();
    if (find==true)
    {
        remove("tickets.txt") ;
        rename("tickets_new.txt", "tickets.txt");
        return 1;
    }
    else
    {
        return 0;
    }
}

struct ti
{
    int id;
    string from;
    string where;
    string date_go;
    string date_return;
    int price;
    int co_cert;
    int visa_cert;
};

void tickets::sort_tickets()
{
    vector<ti> tc;
    ifstream fileoutput("tickets.txt");
    ti ticket;
    while (fileoutput >> ticket.id >> ticket.from >> ticket.where >> ticket.date_go >> ticket.date_return >> ticket.price >> ticket.co_cert >> ticket.visa_cert)
    {
        tc.push_back(ticket);
    }
    sort(tc.begin(), tc.end(), [](const ti &a, const ti &b)
    {
        return a.price > b.price;
    });
    fileoutput.close();
    ofstream fileinput("tickets.txt");
    for (const auto &t : tc)
    {
        fileinput << t.id << " " << t.from << " " << t.where << " " << t.date_go << " " << t.date_return << " " << t.price << " " << t.co_cert << " " << t.visa_cert << endl;
    }
    fileinput.close();
}
