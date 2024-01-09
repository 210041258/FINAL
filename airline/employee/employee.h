#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#define bouns_driver 5%
#define bouns_repairman 2%
#define bouns_host 7%
#define salary_driver 30000
#define salary_repairman 10000
#define salary_host 50000
#define head 15000000
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#define delay sleep(5);
#define wait_and_clear sleep(3); system("cls");
#include "../tickets/tickets.h"

// apply this topic inside the project
/*enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun};

int main()
{
    enum week day;
    day = Wed;
    printf("%d",day);
    return 0;
} */
class employee {
public:
    employee();
    employee(int _Id,string _name,string _Job,float _Salary,string _DoJ);
    int add_employee();
    int edit_employee();//?
    int delete_employee(int id);//?
    void save_employee();
    void update_employee(int id__);
    int search_employee(int id);
    employee extract_employee(int id);//?
    int add_duty();
    int edit_duty();//?
    int delete_duty();//?
    void show_all_duties();// manager function
    void check_duty(int id);// manager function
    int give_access_id();
    string give_access_name();
    string give_access_Job();
    float give_access_Salary();
    string give_access_DoJ();
    void edit_access_id(int i);
    void edit_access_job(string str);
    void edit_access_name(string _name);
    void edit_access_DoJ(string str_new);
    void edit_access_Salary(float say);
private:
    int id;
    string name;
    string job;
    float Salary;
    string DoJ;
};
#endif
